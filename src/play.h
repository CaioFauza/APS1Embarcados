/*
 * play.h
 *
 * Created: 3/30/2020 7:27:55 PM
 *  Author: Caio, Pedro Paulo
 */ 


#ifndef PLAY_H_
#define PLAY_H_

//Buzzer
#define BUZZER_PIO           PIOA
#define BUZZER_PIO_ID        ID_PIOA
#define BUZZER_PIO_IDX       4
#define BUZZER_PIO_IDX_MASK  (1 << BUZZER_PIO_IDX)

//Button 1 - OLed
#define BUT1_PIO PIOD
#define BUT1_PIO_ID ID_PIOD
#define BUT1_PIO_IDX 28
#define BUT1_PIO_IDX_MASK (1u << BUT1_PIO_IDX)

//Button 2 - OLed
#define BUT2_PIO PIOC
#define BUT2_PIO_ID ID_PIOC
#define BUT2_PIO_IDX 31
#define BUT2_PIO_IDX_MASK (1 << BUT2_PIO_IDX)

//Button - Board
#define BUTB_PIO PIOA
#define BUTB_PIO_ID ID_PIOA
#define BUTB_PIO_IDX 11
#define BUTB_PIO_IDX_MASK (1u << BUTB_PIO_IDX)

//LED0 - LED1 OLED BOARD
#define LED0_PIO PIOA
#define LED0_PIO_ID ID_PIOA
#define LED0_PIO_IDX 0
#define LED0_PIO_IDX_MASK (1 << LED0_PIO_IDX)

//LED1 - LED2 OLED BOARD
#define LED1_PIO PIOC
#define LED1_PIO_ID ID_PIOC
#define LED1_PIO_IDX 30
#define LED1_PIO_IDX_MASK (1 << LED1_PIO_IDX)

//LED2 - LED3 OLED BOARD
#define LED2_PIO PIOB
#define LED2_PIO_ID ID_PIOB
#define LED2_PIO_IDX 2
#define LED2_PIO_IDX_MASK (1 << LED2_PIO_IDX)

//LED 3 - Board
#define LED_PIO      PIOC
#define LED_PIO_ID   ID_PIOC
#define LED_IDX      8
#define LED_IDX_MASK (1 << LED_IDX)


volatile char play;
volatile char previous_music;
volatile char next_music;

typedef struct {
	int song[500];
	int tempo[500];
} music;

void play_music(music music_struct, int speed);
void pause_music(void);

#endif /* PLAY_H_ */