#pragma once
#include "PhoneInterface.h"

class S21 : public IPhone,IWireChargable,IARable,IBiometricsable
{
public:
	S21();
	~S21();

	virtual void call(std::string number);
	virtual void message(std::string number, std::string text); 

	virtual void wirelessCharge();
	virtual void AR();
	virtual void biometrcs();
};

class S3 : public IPhone
{
public:
	S3();
	~S3();

	virtual void call(std::string number);
	virtual void message(std::string number, std::string text);


};