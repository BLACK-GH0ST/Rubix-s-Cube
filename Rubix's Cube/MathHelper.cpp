#include "MathHelper.h"
#include <float.h>
#include <cmath>

using namespace DirectX;

const float MathHelper::Infinity = FLT_MAX;
const float MathHelper::Pi = 3.1415926535f;

float MathHelper::AngleFromXY(float x, float y) {
    float theta = .0f;

    if(x >= .0f) {
        theta = atanf(y / x);
        if(theta < .0f)
            theta += 2.f * Pi;
    }
        else
            theta = atan(y / x) + Pi;
        return theta;
}

    XMVECTOR MathHelper::RandUnitVec3() {
        XMVECTOR One = XMVectorSet(1.f, 1.f, 1.f, 1.f);
        XMVECTOR Zero = XMVectorZero();

        while(true)  {
            XMVECTOR v = XMVectorSet(
                MathHelper::RandF(-1.f, 1.f),
                MathHelper::RandF(-1.f, 1.f),
                MathHelper::RandF(-1.f, 1.f),
                .0f);
            if(XMVector3Greater(XMVector3LengthSq(v), One))
                continue;
            return XMVector3Normalize(v);
        }
    }

    XMVECTOR MathHelper::RandHemisphereUnitVec3(XMVECTOR n) {
        XMVECTOR One = XMVectorSet(1.f, 1.f, 1.f, 1.f);
        XMVECTOR Zero = XMVectorZero();
        while(true) {
            XMVECTOR v = XMVectorSet(MathHelper::RandF(-1.f, 1.f),
                                     MathHelper::RandF(-1.f, 1.f),
                                     MathHelper::RandF(-1.f, 1.f),
                                     .0f);
            if(XMVector3Greater(XMVector3Length(v), One))
                continue;
            return XMVector3Normalize(v);
        }
    }