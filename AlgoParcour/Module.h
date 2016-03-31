#pragma once

#include "stdafx.h"

class Module
{
public:
    Module(const std::string& name, int reading, int writing, int maths, int fun);
    Module(int reading, int writing, int maths, int fun);
    Module(const Module& m);
    ~Module();

    const std::string& getName() const;
    int getReading() const;
    int getWriting() const;
    int getMaths() const;
    int getFun() const;

    Module& operator=(const Module& other);
    Module operator+(const Module& other) const;
    Module operator-(const Module& other) const;
    Module operator-() const;
    Module operator*(const int& x) const;
    Module operator/(const int& x) const;
    bool operator==(const Module& other) const;


    std::string toString() const;

private:
    std::string m_name;
    int m_reading;
    int m_writing;
    int m_maths;
    int m_fun;
};

std::ostream& operator<<(std::ostream& flux, const Module& module);
std::ostream& operator<<(std::ostream& flux, const Module*& module);
