#pragma once

#include "stdafx.h"

class Module
{
public:
    Module(const std::string& name, int reading, int writing, int maths, int fun);
    Module(const std::string& name);
    Module(int reading, int writing, int maths, int fun);
    Module(int x);
    Module();
    Module(const Module& m);
    virtual ~Module();

    const std::string& getName() const;
    int getReading() const;
    int getWriting() const;
    int getMaths() const;
    int getFun() const;
    int totalValue() const;

    Module* inferiorLevel() const;

    Module& operator=(const Module& other);
    Module operator+(const Module& other) const;
    Module operator-(const Module& other) const;
    Module operator-() const;
    Module operator*(const int& x) const;
    Module operator/(const int& x) const;
    Module& operator+=(const Module& other);
    bool operator==(const Module& other) const;
    friend Module max(const Module& m1, const Module& m2);
    friend Module min(const Module& m1, const Module& m2);
    friend std::ostream& operator<<(std::ostream& flux, const Module& module);
    friend std::ostream& operator<<(std::ostream& flux, const Module*& module);

    std::string toString() const;

    friend int calculateScore(const Module& current, const Module& concurrent, const Module& diff);

private:
    std::string m_name;
    int m_reading;
    int m_writing;
    int m_maths;
    int m_fun;
};

int calculateScore(int current, int concurrent, int diff);
