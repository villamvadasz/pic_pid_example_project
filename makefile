# MPLAB IDE generated this makefile for use with GNU make.
# Project: p18f4550example.mcp
# Date: Fri Nov 28 22:49:26 2025

AS = MPASMWIN.exe
CC = mcc18.exe
LD = mplink.exe
AR = mplib.exe
RM = rm

./output/p18f4550example.cof : output/main.o output/pid.o output/scaler.o output/signalprocessor.o output/hyst.o output/controller.o
	$(LD) /l"C:\MCC18\lib" /k".\lnk" "lnk\18f4550.lkr" "output\main.o" "output\pid.o" "output\scaler.o" "output\signalprocessor.o" "output\hyst.o" "output\controller.o" /z__MPLAB_BUILD=1 /z__MPLAB_DEBUG=1 /m".\output\p18f4550example.map" /w /o".\output\p18f4550example.cof"

output/main.o : src/main.c ../../MCC18/h/stdio.h pic_pid/inc/scaler.h pic_pid/inc/signalprocessor.h pic_pid/inc/pid.h pic_pid/inc/controller.h pic_pid/inc/hyst.h src/main.c ../../MCC18/h/p18f4550.h inc/global.h inc/main.h ../../MCC18/h/stdarg.h ../../MCC18/h/stddef.h
	$(CC) -p=18F4550 /i".\pic_pid\inc" -I".\inc" "src\main.c" -fo=".\output\main.o" -D__DEBUG -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-

output/pid.o : pic_pid/src/pid.c pic_pid/inc/signalprocessor.h pic_pid/inc/pid.h pic_pid/src/pid.c inc/global.h
	$(CC) -p=18F4550 /i".\pic_pid\inc" -I".\inc" "pic_pid\src\pid.c" -fo=".\output\pid.o" -D__DEBUG -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-

output/scaler.o : pic_pid/src/scaler.c pic_pid/inc/scaler.h pic_pid/src/scaler.c inc/global.h
	$(CC) -p=18F4550 /i".\pic_pid\inc" -I".\inc" "pic_pid\src\scaler.c" -fo=".\output\scaler.o" -D__DEBUG -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-

output/signalprocessor.o : pic_pid/src/signalprocessor.c pic_pid/inc/signalprocessor.h pic_pid/src/signalprocessor.c inc/global.h
	$(CC) -p=18F4550 /i".\pic_pid\inc" -I".\inc" "pic_pid\src\signalprocessor.c" -fo=".\output\signalprocessor.o" -D__DEBUG -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-

output/hyst.o : pic_pid/src/hyst.c pic_pid/inc/hyst.h pic_pid/src/hyst.c inc/global.h
	$(CC) -p=18F4550 /i".\pic_pid\inc" -I".\inc" "pic_pid\src\hyst.c" -fo=".\output\hyst.o" -D__DEBUG -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-

output/controller.o : pic_pid/src/controller.c ../../MCC18/h/stdio.h pic_pid/inc/scaler.h pic_pid/inc/signalprocessor.h pic_pid/inc/pid.h pic_pid/inc/controller.h pic_pid/src/controller.c ../../MCC18/h/stdarg.h ../../MCC18/h/stddef.h inc/global.h
	$(CC) -p=18F4550 /i".\pic_pid\inc" -I".\inc" "pic_pid\src\controller.c" -fo=".\output\controller.o" -D__DEBUG -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-

clean : 
	$(RM) "output\main.o" "output\pid.o" "output\scaler.o" "output\signalprocessor.o" "output\hyst.o" "output\controller.o" ".\output\p18f4550example.cof" ".\output\p18f4550example.hex" ".\output\p18f4550example.map"

