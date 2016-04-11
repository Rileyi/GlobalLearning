#pragma once

#include "stdafx.h"

enum Matter {Reading, Writing, Maths, Fun, Size};

class Module
{
public:
    Module(const std::string& name, int reading, int writing, int maths, int fun);
    Module(const std::string& name, const std::vector<int>& learnings);
    Module(const std::string& name);
    Module(int reading, int writing, int maths, int fun);
    Module(const std::vector<int>& learnings);
    Module(int x);
    Module();
    Module(const Module& m);
    virtual ~Module();

    const std::string& getModuleName() const;
    void setModuleName(const std::string name);
    const std::vector<int>& getlearnings() const;
    Matter mainMatter() const;
    int totalValue() const;

    Module* inferiorLevel() const;

    Module& operator=(const Module& other);
    Module operator+(const Module& other) const;
    Module operator-(const Module& other) const;
    Module operator-() const;
    Module operator*(const int& x) const;
    Module operator/(const int& x) const;
    Module& operator+=(const Module& other);
    Module& operator-=(const Module& other);
    Module& operator*=(const int& x);
    Module& operator/=(const int& x);
    bool operator==(const Module& other) const;
    int& operator[](const Matter& matter);
    int& operator[](const int& matter);
    int operator[](const Matter& matter) const;
    int operator[](const int& matter) const;
    friend Module max(const Module& m1, const Module& m2);
    friend Module min(const Module& m1, const Module& m2);
    friend std::ostream& operator<<(std::ostream& flux, const Module& module);

    std::string toString() const;

private:
    std::string m_name;
    std::vector<int> m_learnings;
};

int calculateScore(const Module& current, const Module& concurrent, const Module& diff);
