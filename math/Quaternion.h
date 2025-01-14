#pragma once


/// <summary>
/// Quaternion
/// </summary>
class Quaternion
{
public:
    /// データ
    float x,y,z,w;

    /// <returns>単位Quaternion</returns>
    static Quaternion Identity();

    /// <returns>共役Quaternion</returns>
    static Quaternion Conjugate(const Quaternion& _q);

    /// <returns>ノルム</returns>
    float Norm() const;

    /// <returns>正規化したQuaternion</returns>
    Quaternion Normalized() const;

    /// <returns>逆Quaternionを返す</returns>
    Quaternion Inversed() const;
    
    Quaternion operator *(const Quaternion& _rq) const;
    Quaternion operator /(float _f) const;
};