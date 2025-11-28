# MPLAB IDE generated this makefile for use with GNU make.
# Project: p18f4550example.mcp
# Date: Fri Sep 04 17:19:52 2009

AS = MPASMWIN.exe
CC = mcc18.exe
LD = mplink.exe
AR = mplib.exe
RM = rm

output/p18f4550example.cof : output/signalprocessor.o output/controller.o output/hyst.o output/pid.o output/scaler.o output/main.o
	$(LD) /l"C:\MCC18\lib" /k"C:\temp\library\pic\pid\software\lnk" "lnk\18f4550.lkr" "output\signalprocessor.o" "output\controller.o" "output\hyst.o" "output\pid.o" "output\scaler.o" "output\main.o" /u_CRUNTIME /u_DEBUG /z__MPLAB_BUILD=1 /z__MPLAB_DEBUG=1 /o"C:\temp\library\pic\pid\software\output\p18f4550example.cof" /M"C:\temp\library\pic\pid\software\output\p18f4550example.map" /W

output/signalprocessor.o : src/pid/signalprocessor.c inc/pid/signalprocessor.h src/pid/signalprocessor.c inc/global.h
	$(CC) -p=18F4550 /i"C:\temp\library\pic\pid\software\inc\pid" -I"C:\temp\library\pic\pid\software\inc" "src\pid\signalprocessor.c" -fo="C:\temp\library\pic\pid\software\output\signalprocessor.o" -D__DEBUG -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-

output/controller.o : src/pid/controller.c ../../../../../MCC18/h/stdio.h inc/pid/scaler.h inc/pid/signalprocessor.h inc/pid/pid.h inc/pid/controller.h src/pid/controller.c ../../../../../MCC18/h/stdarg.h ../../../../../MCC18/h/stddef.h inc/global.h
	$(CC) -p=18F4550 /i"C:\temp\library\pic\pid\software\inc\pid" -I"C:\temp\library\pic\pid\software\inc" "src\pid\controller.c" -fo="C:\temp\library\pic\pid\software\output\controller.o" -D__DEBUG -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-

output/hyst.o : src/pid/hyst.c inc/pid/hyst.h src/pid/hyst.c inc/global.h
	$(CC) -p=18F4550 /i"C:\temp\library\pic\pid\software\inc\pid" -I"C:\temp\library\pic\pid\software\inc" "src\pid\hyst.c" -fo="C:\temp\library\pic\pid\software\output\hyst.o" -D__DEBUG -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-

output/pid.o : src/pid/pid.c inc/pid/signalprocessor.h inc/pid/pid.h src/pid/pid.c inc/global.h
	$(CC) -p=18F4550 /i"C:\temp\library\pic\pid\software\inc\pid" -I"C:\temp\library\pic\pid\software\inc" "src\pid\pid.c" -fo="C:\temp\library\pic\pid\software\output\pid.o" -D__DEBUG -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-

output/scaler.o : src/pid/scaler.c inc/pid/scaler.h src/pid/scaler.c inc/global.h
	$(CC) -p=18F4550 /i"C:\temp\library\pic\pid\software\inc\pid" -I"C:\temp\library\pic\pid\software\inc" "src\pid\scaler.c" -fo="C:\temp\library\pic\pid\software\output\scaler.o" -D__DEBUG -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-

output/main.o : src/main.c ../../../../../MCC18/h/stdio.h inc/pid/scaler.h inc/pid/signalprocessor.h inc/pid/pid.h inc/pid/controller.h inc/pid/hyst.h src/main.c ../../../../../MCC18/h/p18f4550.h inc/global.h inc/main.h ../../../../../MCC18/h/stdarg.h ../../../../../MCC18/h/stddef.h
	$(CC) -p=18F4550 /i"C:\temp\library\pic\pid\software\inc\pid" -I"C:\temp\library\pic\pid\software\inc" "src\main.c" -fo="C:\temp\library\pic\pid\software\output\main.o" -D__DEBUG -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-

clean : 
	$(RM) "output\signalprocessor.o" "output\controller.o" "output\hyst.o" "output\pid.o" "output\scaler.o" "output\main.o" "output\p18f4550example.cof" "output\p18f4550example.hex"

