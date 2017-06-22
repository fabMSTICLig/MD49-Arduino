/*
  MD49.h - Library for MD49 controller
  Created by Germain Lemasson, June 22, 2017.
  Released into the public domain.
*/

#ifndef MD49_H
#define MD49_H
#include <Arduino.h>

typedef enum MD49_MODE_t {MD49_MODE0=0,MD49_MODE1,MD49_MODE2,MD49_MODE3};

class MD49{
private:
	HardwareSerial & m_serial;
	MD49_MODE_t m_mode;

	unsigned long m_timeout;
	void sendCmd(byte cmd,byte val=0);
	byte getByte();
	int getInt();
	boolean checkspeed(int val);
public:
	MD49(HardwareSerial & serial);
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


#endif
