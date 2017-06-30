#ifndef MD49_H
#define MD49_H
#include <Arduino.h>
typedef enum MD49_MODE_t {MD49_MODE0=0,MD49_MODE1,MD49_MODE2,MD49_MODE3};
template<typename S> class MD49{
private:
S & m_serial;
MD49_MODE_t m_mode;

unsigned long m_timeout;
void sendCmd(byte cmd,byte val=0);
byte getByte();
int getInt();
boolean checkspeed(int val);
public:
MD49(S & serial);
void init(int baud);
int getSpeed(byte num);
int getTurn();
int getCurrent(byte num);
int getEncoder(byte num);
void getEncoders(int * encs);
int getVolt();
int getAccel();
MD49_MODE_t getMode();
byte getError();

void setSpeed1(int speed);
void setSpeed2(int speed);
void setTurn(int turn);
void setAccel(byte acc);
void setMode(MD49_MODE_t mode);
void resetEncoder();
void setRegulator(boolean on);
void setTimeout(boolean on);
void stop();

};

#include<MD49.tpp>


#endif
