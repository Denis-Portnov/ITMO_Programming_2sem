#pragma once

class IPhysObject {
public:
    virtual double mass() const= 0;

    virtual CVector2D position() const = 0;

    virtual bool operator==(const IPhysObject &ob) const = 0;

    virtual bool operator<(const IPhysObject &ob) const = 0;
};