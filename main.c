
#include <stdio.h>
#include <esp_log.h>
#include <string.h>
#include "driver/uart.h"
#include "esp_system.h"
#include "esp_console.h"
#include "nvs.h"
#include "nvs_flash.h"

#define PROMPT_STR CONFIG_IDF_TARGET
/*
#define TAG "MY TAG"
*/
void app_main(void)
{
 //   printf("Hello Word\n");
//    ESP_LOGI("TAG","Message");

/********************************************************************
 * Read serial data from the serial port
 *  printf and scanf via the console without UART definitions Using
 * #include "driver/uart.h"
 * *******************************************************************
*/
#if(0)
    char chr[10];
    while(1){
        printf("\nEnter Data : ");
        scanf("%9s", chr);
        printf("\nData entered : %s\n", chr);
        strcpy(chr, "");
        vTaskDelay(5000 / portTICK_PERIOD_MS);
    }
#endif
// Console initiation
    nvs_flash_init();
    esp_console_register_help_command();

    // REPL (Read-Evaluate-Print-Loop) environment
    esp_console_repl_t *repl = NULL;
    esp_console_repl_config_t repl_config = ESP_CONSOLE_REPL_CONFIG_DEFAULT();
    repl_config.prompt = PROMPT_STR ">";
    esp_console_dev_uart_config_t hw_config = ESP_CONSOLE_DEV_UART_CONFIG_DEFAULT();
    esp_console_new_repl_uart(&hw_config, &repl_config, &repl);
    esp_console_start_repl(repl);

}
