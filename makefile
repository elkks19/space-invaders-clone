CFLAGS:= -pthread
GCC:= gcc
CC:= g++
RM:= rm
#glfw lib flags
LFLAGS:= -lGLEW -lGLU -lGL -lglfw

.PHONY: $(TARGET)
.PHONY: clean
.PHONY: run
.PHONY: again


#LAS RUTAS PARA LOS ARCHIVOS .c, .o y .h (en ese orden)
SRCPATH = ./src/
OBJPATH = ./obj/
INCLUDEPATH = -I./include \

#NOMBRE DEL EJECUTABLE
TARGET := tetris


#ARCHIVOS A COMPILAR
OBJ1:=  main.o \


OBJ:= $(patsubst %,$(OBJPATH)%, $(OBJ1))


#PRIMERO SE COMPILAN LOS ARCHIVOS .c
$(OBJPATH)%.o: $(SRCPATH)%.c
	@echo [GCC] $<
	@$(GCC) $(CFLAGS) -o $@ -c $< $(INCLUDEPATH) $(LFLAGS)

# la parte que compila los .cpp
$(OBJPATH)%.o: $(SRCPATH)%.cpp
	@echo [CC] $<
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDEPATH) $(LFLAGS)

#LINKEAMOS TODO:
$(TARGET): $(OBJ)
	@echo [INFO] Creando ejecutable binario [$(TARGET)]
	@$(CC) -o $@ $^ $(LFLAGS)


# LIMPIAR TODOS LOS ARCHIVOS .o Y EL EJECUTABLE
clean:   
	@echo "[Limpiando...]"
	@$(RM) -rfv $(OBJPATH)*
	@$(RM) -rfv $(TARGET)

run: $(TARGET)
	@echo "[Ejecutando...]"
	@./$(TARGET)

#RECOMPILAR
again: clean run
	@echo "[Recompilando...]"

