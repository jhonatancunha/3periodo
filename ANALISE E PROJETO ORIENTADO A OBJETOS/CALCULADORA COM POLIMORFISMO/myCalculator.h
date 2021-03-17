/**
 * This file defines the interfaces of a calculator and its components.
 * Author: Lucio Valentin
 * Version: 20210316
 */
#include "interface.h"
#include <iostream>

class MyDisplay : public Display{
  public:
    void addDigit(Digit number); // Adiciona um dígito na tela
    void addDecimalSeparator(); // Aciona o separador de casas decimais
    void setSignal(Signal signal); // Define o sinal positivo ou negativo
    void clear(); // Limpa todos os dígitos
};

class MyCpu : public Cpu{
  private:
    static const int maxDigits = 8;
    Display *display;
    Digit operandOne[maxDigits];
    Digit operandTwo[maxDigits];
    int operandOneCounter;
    int operandTwoCounter;
    Operation operation;

    int digitToInt(Digit *operand, int count);
    void intToDigit(int result);
    void calculate();
    
  public:
    MyCpu();
    void setDisplay(Display* display); // Conecta uma tela para a CPU

    void receiveDigit(Digit digit); // Envia um dígito para o operando corrente
    void receiveOperation(Operation operation); // Envia a operação e troca o operando corrente
    void cancel(); // Cancela os dígitos do operando corrente
    void reset(); // Cancela todos operandos e operação
};


class MyOperationKeyBoard : public OperationKeyBoard{
  private:
    Cpu *cpu;

  public:
    void setCpu(Cpu *cpu);
    
    void pressAddition();
    void pressDivision();
    void pressMultiplication();
    void pressSubtraction();
    void pressEquals();
};

class MyNumericKeyBoard : public NumericKeyBoard{
  private:
    Cpu *cpu;

  public:
    void setCpu(Cpu *cpu);
    
    void pressZero();
    void pressOne();
    void pressTwo();
    void pressThree();
    void pressFour();
    void pressFive();
    void pressSix();
    void pressSeven();
    void pressEight();
    void pressNine();
};

class MyCalculator : public Calculator{
  private:
    Cpu* cpu;
    Display* display;
    NumericKeyBoard* numericKeyBoard;
    OperationKeyBoard* operationKeyBoard;

  public:
    MyCalculator(Cpu *cpu, Display *display, NumericKeyBoard *numericKeyBoard, OperationKeyBoard *operationKeyBoard);
    ~MyCalculator();

    void setNumericKeyBoard(NumericKeyBoard* numericKeyBoard);
    NumericKeyBoard* getNumericKeyBoard();
    
    void setOperationKeyBoard(OperationKeyBoard* operationKeyBoard);
    OperationKeyBoard* getOperationKeyBoard();

    void setDisplay(Display* display);
    Display* getDisplay();

    void setCpu(Cpu* cpu);
    Cpu* getCpu();
};
