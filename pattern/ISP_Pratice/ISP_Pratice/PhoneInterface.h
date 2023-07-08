#pragma once

#include <string>

class IPhone
{
public:
	virtual void call(std::string number) abstract;
	virtual void message(std::string number, std::string text) abstract;
};

class IWireChargable
{
public:
	virtual void wirelessCharge() abstract;
};

class IARable
{
public:
	virtual void AR() abstract;
};

class IBiometricsable
{
public:
	virtual void biometrcs() abstract;
};