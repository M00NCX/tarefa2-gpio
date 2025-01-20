#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"

#define LED_GREEN 11
#define LED_BLUE 12
#define LED_RED 13
#define BUZZER 21

// Inicializa os GPIOs dos LEDs e do buzzer
void init_gpio()
{
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);

    gpio_init(LED_BLUE);
    gpio_set_dir(LED_BLUE, GPIO_OUT);

    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);

    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);
}

// Liga o LED especificado
void turn_on_led(uint pin)
{
    gpio_put(pin, 1);
}

// Desliga todos os LEDs
void turn_off_all_leds()
{
    gpio_put(LED_GREEN, 0);
    gpio_put(LED_BLUE, 0);
    gpio_put(LED_RED, 0);
}

// Emite um sinal sonoro no buzzer por 2 segundos
void beep_buzzer()
{
    gpio_put(BUZZER, 1);
    sleep_ms(2000);
    gpio_put(BUZZER, 0);
}

int main()
{
    stdio_init_all(); // Inicializa UART
    init_gpio();

    printf("Sistema iniciado. Pronto para comandos.\n");
    printf("Comandos disponíveis:\n");
    printf("  GREEN - Ligar LED verde\n");
    printf("  BLUE - Ligar LED azul\n");
    printf("  RED - Ligar LED vermelho\n");
    printf("  WHITE - Ligar todos os LEDs (luz branca)\n");
    printf("  OFF - Desligar todos os LEDs\n");
    printf("  BEEP - Acionar o buzzer\n");

    char command[10];
    while (1)
    {
        if (scanf("%s", command) == 1)
        {
            turn_off_all_leds(); // Desliga todos os LEDs antes de cada comando

            if (strcmp(command, "GREEN") == 0)
            {
                turn_on_led(LED_GREEN);
                printf("LED verde ligado.\n");
            }
            else if (strcmp(command, "BLUE") == 0)
            {
                turn_on_led(LED_BLUE);
                printf("LED azul ligado.\n");
            }
            else if (strcmp(command, "RED") == 0)
            {
                turn_on_led(LED_RED);
                printf("LED vermelho ligado.\n");
            }
            else if (strcmp(command, "WHITE") == 0)
            {
                turn_on_led(LED_GREEN);
                turn_on_led(LED_BLUE);
                turn_on_led(LED_RED);
                printf("Todos os LEDs ligados (luz branca).\n");
            }
            else if (strcmp(command, "OFF") == 0)
            {
                turn_off_all_leds();
                printf("Todos os LEDs desligados.\n");
            }
            else if (strcmp(command, "BEEP") == 0)
            {
                beep_buzzer();
                printf("Buzzer acionado.\n");
            }
            else
            {
                printf("Comando não reconhecido: %s\n", command);
            }
        }
    }
    return 0;
}
