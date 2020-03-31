/*
 * play.c
 *
 * Created: 3/30/2020 7:27:46 PM
 *  Author: Caio, Pedro Paulo
 */ 
#include "asf.h"
#include "play.h"


void pause_music(void){
	play = 0;
	while(1){
		if(play){
			play = 0;
			break;
		}
	}
}

void play_music(music music_struct, int speed){
	int size = sizeof(music_struct.song)/sizeof(int);
	int size_2 = sizeof(music_struct.tempo)/sizeof(int);
	for (int i=0;i<size;i++){
		pio_clear(LED_PIO, LED_IDX_MASK);
		pio_clear(LED0_PIO, LED0_PIO_IDX_MASK);
		pio_clear(LED1_PIO, LED1_PIO_IDX_MASK);
		pio_clear(LED2_PIO, LED2_PIO_IDX_MASK);
		for(int j=0; j<size_2/speed; j++){
			if(play){
				delay_ms(300);
				pause_music();
			}
			if(next_music || previous_music){
				delay_ms(300);
				return;
			}
			
			pio_set(BUZZER_PIO, BUZZER_PIO_IDX_MASK);
			delay_us(1000000/(music_struct.song[i]*2));
			pio_clear(BUZZER_PIO, BUZZER_PIO_IDX_MASK);
			delay_us(1000000/(music_struct.song[i]*2));
			pio_set(LED_PIO, LED_IDX_MASK);
			pio_set(LED0_PIO, LED0_PIO_IDX_MASK);
			pio_set(LED1_PIO, LED1_PIO_IDX_MASK);
			pio_set(LED2_PIO, LED2_PIO_IDX_MASK);
		}
	}
}