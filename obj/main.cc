#include <wiringPi.h>
#include <wiringPiSPI.h>

#include <stdio.h>  //printf()
#include <stdlib.h> //exit()
#include <time.h>

#include "LCD_Driver.h"
#include "LCD_GUI.h"
#include "LCD_BMP.h"
#include "DEV_Config.h"

 //#include <string>
#include <node.h>
// //#include "nan.h"

using v8::Exception;
using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;

void init(const FunctionCallbackInfo<Value> &args)
{
	if (System_Init())
		exit(0);

	//2.show
	printf("**********Init LCD**********\r\n");
	LCD_SCAN_DIR LCD_ScanDir = SCAN_DIR_DFT; //SCAN_DIR_DFT = D2U_L2R
	LCD_Init(LCD_ScanDir);

	printf("LCD Show \r\n");
	GUI_Show();
}

#if 0 // This is an unlucky try with NAN
NAN_METHOD(drawstring)
{
  NanScope();
  static NanAsciiString *str;
  str = new NanAsciiString(arg[2]);
  NanReturnUndefined();

  LCDdrawstring_P(args[0]->NumberValue(),
    args[1]->NumberValue(),
    str ? str : "");

  LCDdisplay();

  delay(100000);
}
#endif

void Initialize(Local<Object> exports)
{
	NODE_SET_METHOD(exports, "init", init);
	// NODE_SET_METHOD(exports, "setcontrast", setcontrast);
	// NODE_SET_METHOD(exports, "clear", clear);
	NODE_SET_METHOD(exports, "drawstring", drawstring);
	// NODE_SET_METHOD(exports, "display", display);
}

NODE_MODULE(my_lcd, Initialize)

// int main(void)
// {
// 	//1.System Initialization
// 	if(System_Init())
// 		exit(0);

// 	//2.show
// 	printf("**********Init LCD**********\r\n");
// 	LCD_SCAN_DIR LCD_ScanDir = SCAN_DIR_DFT;//SCAN_DIR_DFT = D2U_L2R
// 	LCD_Init(LCD_ScanDir );

// 	printf("LCD Show \r\n");
// 	GUI_Show();
// 	Driver_Delay_ms(1000);

// 	printf("show bmp\r\n");
// 	LCD_ShowBmp("./pic/time.bmp");

// 	//3.System Exit
// 	System_Exit();
// 	return 0;

// }