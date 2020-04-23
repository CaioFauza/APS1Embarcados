#include "musics.h"
#include "play.h"
#include "gfx_mono_ug_2832hsweg04.h"
#include "gfx_mono_text.h"
#include "sysfont.h"

volatile char play = 0;
volatile char previous_music = 0;
volatile char next_music = 0;

music mario_music;
music pirate_music;
music underworld_music;


void but_callback1(void){
	next_music = 1;
}

void but_callback2(void){
	play = 1;
}

void but_callback3(void){
	previous_music = 1;
}


void init(void){
	
	sysclk_init();
	board_init();
	delay_init();
	WDT->WDT_MR = WDT_MR_WDDIS;
	
	//OLed
	gfx_mono_ssd1306_init();
	
	
	//Buzzer
	pmc_enable_periph_clk(BUZZER_PIO_ID);
	pio_set_output(BUZZER_PIO, BUZZER_PIO_IDX_MASK, 0, 0, 0);
	
	//Button 1 - OLed
	pmc_enable_periph_clk(BUT1_PIO_ID);
	pio_set_input(BUT1_PIO, BUT1_PIO_IDX_MASK, PIO_PULLUP);

	//Button 2 - OLed
	pmc_enable_periph_clk(BUT2_PIO_ID);
	pio_set_input(BUT2_PIO, BUT2_PIO_IDX_MASK, PIO_PULLUP);
	
	//Button 3 - Board
	pmc_enable_periph_clk(BUTB_PIO_ID);
	pio_set_input(BUTB_PIO, BUTB_PIO_IDX_MASK, PIO_PULLUP);
	
	//Led 3 - Board
	pmc_enable_periph_clk(LED_PIO_ID);
	pio_set_output(LED_PIO, LED_IDX_MASK, 0, 0, 0);
	
	//Led 0 - OLed
	pmc_enable_periph_clk(LED0_PIO_ID);
	pio_set_output(LED0_PIO, LED0_PIO_IDX_MASK, 0, 0, 0);
	
	//Led 1 - OLed
	pmc_enable_periph_clk(LED1_PIO_ID);
	pio_set_output(LED1_PIO, LED1_PIO_IDX_MASK, 0, 0, 0);
	
	//Led 2 - OLed
	pmc_enable_periph_clk(LED2_PIO_ID);
	pio_set_output(LED2_PIO, LED2_PIO_IDX_MASK, 0, 0, 0);
	
	//Button 1 - OLed
	pio_configure(BUT1_PIO, PIO_INPUT, BUT1_PIO_IDX_MASK, PIO_PULLUP);
	pio_handler_set(BUT1_PIO,
	BUT1_PIO_ID,
	BUT1_PIO_IDX_MASK,
	PIO_IT_FALL_EDGE,
	but_callback1);
	
	//Button 2 - OLed
	pio_configure(BUT2_PIO, PIO_INPUT, BUT2_PIO_IDX_MASK, PIO_PULLUP);
	pio_handler_set(BUT2_PIO,
	BUT2_PIO_ID,
	BUT2_PIO_IDX_MASK,
	PIO_IT_FALL_EDGE,
	but_callback2);
	
	//Button 3 - Board
	pio_configure(BUTB_PIO, PIO_INPUT, BUTB_PIO_IDX_MASK, PIO_PULLUP);
	pio_handler_set(BUTB_PIO,
	BUTB_PIO_ID,
	BUTB_PIO_IDX_MASK,
	PIO_IT_FALL_EDGE,
	but_callback3);
	
	pio_enable_interrupt(BUT1_PIO, BUT1_PIO_IDX_MASK);
	pio_enable_interrupt(BUT2_PIO, BUT2_PIO_IDX_MASK);
	pio_enable_interrupt(BUTB_PIO, BUTB_PIO_IDX_MASK);

	NVIC_EnableIRQ(BUT1_PIO_ID);
	NVIC_SetPriority(BUT1_PIO_ID, 1);
	
	NVIC_EnableIRQ(BUT2_PIO_ID);
	NVIC_SetPriority(BUT2_PIO_ID, 1);
	
	NVIC_EnableIRQ(BUTB_PIO_ID);
	NVIC_SetPriority(BUTB_PIO_ID, 1);
	
	
	for(int i = 0; i < sizeof(music_1)/sizeof(int); i++){
		pirate_music.song[i] = music_1[i];
		pirate_music.tempo[i] = duration_1[i];
	}
	
	for(int j = 0; j < sizeof(music_2)/sizeof(int); j++){
		mario_music.song[j] = music_2[j];
		mario_music.tempo[j] = duration_2[j];
	}
	
	for(int h = 0; h < sizeof(music_3)/sizeof(int); h++){
		underworld_music.song[h] = music_3[h];
		underworld_music.tempo[h] = duration_3[h];
	}	
}


void draw_music_title(char* music) {
	gfx_mono_draw_string(music, 50,16, &sysfont);
}

int main(void){
	init();
	int music_selected = 0;
	char buffer[32];
	while (1){
		if(play){
			play = 0;
			if(music_selected == 0){
				sprintf(buffer, "%8s", "Mario");
				draw_music_title(buffer);
				play_music(mario_music, 1);
				
			}
			if(music_selected == 1){
				sprintf(buffer, "%8s", "Piratas");
				draw_music_title(buffer);
				play_music(pirate_music, 4.5);
				
			}
			if(music_selected == 2){
				sprintf(buffer, "%8s", "Under");
				draw_music_title(buffer);
				play_music(underworld_music, 2.7);
			}
		}
		if(previous_music){
			if(music_selected == 0){
				music_selected = 2;
				} else {
				music_selected--;
			}
			previous_music = 0;
			play = 1;
		}
		if(next_music){
			if(music_selected == 2){
				music_selected = 0;
				} else {
				music_selected++;
			}
			next_music = 0;
			play = 1;
		}
	}
	return 0;
}