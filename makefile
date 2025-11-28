SHELL = cmd
AS = MPASMWIN.exe
CC = mcc18.exe
LD = mplink.exe
AR = mplib.exe
RM = del
PROJECT=p18f4550example
PIC_TYPE=18F4550
MAKEFILENAME=-DMAKEFILE_NAME=\""Makefile\""
DEFAULTDEFINE=$(MAKEFILENAME)
INCLUDEPATH=/i".\pic_pid\inc" -I".\inc"
CFLAGS=-Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-
LIBS=

TARGET := ./output/$(PROJECT).hex
TARGET_COFF := ./output/$(PROJECT).cof
TARGET_MAP := ./output/$(PROJECT).map

all: $(TARGET)

SRC_DIRS := .\src .\pic_pid\src
SRCS := $(wildcard $(addsuffix /*.c, $(SRC_DIRS)))
EXCLUDE := 
SRCS := $(filter-out $(EXCLUDE), $(SRCS))
OBJS := $(SRCS:.c=.o)

SRCS_WIN := $(subst /,\,$(SRCS))
OBJS_WIN := $(subst /,\,$(OBJS))
TARGET_WIN := $(subst /,\,$(TARGET))
TARGET_COFF_WIN := $(subst /,\,$(TARGET_COFF))
TARGET_MAP_WIN := $(subst /,\,$(TARGET_MAP))

$(TARGET) : $(TARGET_COFF)

$(TARGET_COFF) : $(OBJS_WIN)
	$(LD) /l"C:\MCC18\lib" /k".\lnk" "lnk\$(PIC_TYPE).lkr" $^ /z__MPLAB_BUILD=1 /m$(TARGET_MAP_WIN) /w /o$(TARGET_COFF_WIN)

%.o: %.c
	$(CC) -p=$(PIC_TYPE) $(INCLUDEPATH) $< -fo=$@ $(CFLAGS) $(DEFAULTDEFINE)

clean : 
	$(RM) /Q $(OBJS_WIN) $(TARGET_WIN) $(TARGET_COFF_WIN) $(TARGET_MAP_WIN)
