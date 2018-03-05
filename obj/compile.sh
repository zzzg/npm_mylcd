#!/bin/bash

#include "LCD_Driver.h"
#include "LCD_GUI.h"
#include "LCD_BMP.h"
#include "DEV_Config.h"

gcc -o my_lcd_test main_real.cc LCD_Driver.h LCD_GUI.h LCD_BMP.h DEV_Config.h  -L/usr/local/lib -lwiringPi
