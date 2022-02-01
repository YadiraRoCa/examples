#ifndef __QUATERNION__
#define __QUATERNION__

struct Quaternion;
float kmQuaternionDot(const Quaternion* q1, const Quaternion* q2);
int kmQuaternionIsIdentity(const Quaternion* pIn);
float kmQuaternionLengthSq(const Quaternion* pIn);

struct Quaternion {
    Quaternion(float _w, float _x, float _y, float _z):
    w(_w), x(_x), y(_y), z(_z)
    {};

    
    float dot(const Quaternion* q){
        return kmQuaternionDot(this,q);
    }

    int isidentity(){
        return kmQuaternionIsIdentity(this);
    }

    float lensq(){
        return kmQuaternionLengthSq(this);
    }

    float w,x,y,z;
};

float kmQuaternionDot(const Quaternion* q1, const Quaternion* q2)
{
    return (q1->w * q2->w +
        q1->x * q2->x +
        q1->y * q2->y +
        q1->z * q2->z);
}


int kmQuaternionIsIdentity(const Quaternion* pIn)
{
    return (pIn->x == 0.0 && pIn->y == 0.0 && pIn->z == 0.0 &&
                pIn->w == 1.0);
}

float kmQuaternionLengthSq(const Quaternion* pIn)
{
    return pIn->x * pIn->x + pIn->y * pIn->y +
                        pIn->z * pIn->z + pIn->w * pIn->w;
}

#endif
