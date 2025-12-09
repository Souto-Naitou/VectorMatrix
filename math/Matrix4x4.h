#pragma once

/// 前方宣言
class Vector3;
class Quaternion;

/// <summary>
/// 4x4行列
/// </summary>
class Matrix4x4 {
public:
    float m[4][4];

    /// ====================
    /// Minus Sign
    /// ====================
    Matrix4x4 operator-() const;

    /// =====================
    /// Make Matrix
    /// =====================

    /// <summary>
    /// 単位行列を設定
    /// </summary>
    void SetIdentity();

    /// <returns>単位行列</returns>
    static Matrix4x4 Identity();

    /// <returns>X回転行列</returns>
    static Matrix4x4 RotateXMatrix(float radian);

    /// <returns>Y回転行列</returns>
    static Matrix4x4 RotateYMatrix(float radian);

    /// <returns>Z回転行列</returns>
    static Matrix4x4 RotateZMatrix(float radian);

    /// <returns>Quaternionから回転行列を取得</returns>
    static Matrix4x4 RotateMatrix(const Quaternion& q);

    /// <returns>任意軸回転行列</returns>
    static Matrix4x4 RotateAxisAngleMatrix(const Vector3& axis, float angle);

    /// <returns>方向から方向への行列</returns>
    static Matrix4x4 DirectionToDirectionMatrix(const Vector3& from, const Vector3& to);

    /// <summary>
    /// アフィン変換行列
    /// </summary>
    /// <param name="scale">拡縮倍率</param>
    /// <param name="rotate">角度</param>
    /// <param name="translate">座標</param>
    /// <returns></returns>
    static Matrix4x4 AffineMatrix(
        const Vector3& scale,
        const Vector3& rotate,
        const Vector3& translate
    );

    /// <summary>
    /// スケール、回転、平行移動からアフィン変換行列を生成します。
    /// </summary>
    /// <param name="scale">スケーリングを表す3次元ベクトル。</param>
    /// <param name="rotate">回転を表すクォータニオン。</param>
    /// <param name="translate">平行移動を表す3次元ベクトル。</param>
    /// <returns>指定されたスケール、回転、平行移動を適用した4x4のアフィン変換行列。</returns>
    static Matrix4x4 AffineMatrix(
        const Vector3& scale,
        const Quaternion& rotate,
        const Vector3& translate
    );

    /// <summary>
    /// 透視投影行列
    /// </summary>
    /// <param name="fovY">視野角</param>
    /// <param name="aspectRatio">アスペクト比</param>
    /// <param name="nearClip">近クリップ</param>
    /// <param name="farClip">遠クリップ</param>
    /// <returns></returns>
    static Matrix4x4 PerspectiveFovMatrix(
        float fovY,
        float aspectRatio,
        float nearClip,
        float farClip
    );

    /// <summary>
    /// 正射影行列
    /// </summary>
    /// <param name="left">左</param>
    /// <param name="top">上</param>
    /// <param name="right">右</param>
    /// <param name="bottom">下</param>
    /// <param name="nearClip">近クリップ</param>
    /// <param name="farClip">遠クリップ</param>
    /// <returns></returns>
    static Matrix4x4 OrthographicMatrix(
        float left,
        float top,
        float right,
        float bottom,
        float nearClip,
        float farClip
    );

    /// <summary>
    /// ビューポート変換行列
    /// </summary>
    /// <param name="left">左</param>
    /// <param name="top">上</param>
    /// <param name="width">幅</param>
    /// <param name="height">高さ</param>
    /// <param name="minDepth">最小深度</param>
    /// <param name="maxDepth">最大深度</param>
    /// <returns></returns>
    static Matrix4x4 ViewportMatrix(
        float left,
        float top,
        float width,
        float height,
        float minDepth,
        float maxDepth
    );

    /// <summary>
    /// 拡大行列
    /// </summary>
    /// <param name="scale">拡大率</param>
    /// <returns></returns>
    static Matrix4x4 ScaleMatrix(const Vector3& scale);

    /// <summary>
    /// 移動行列
    /// </summary>
    /// <param name="translate">移動量</param>
    /// <returns></returns>
    static Matrix4x4 TranslateMatrix(const Vector3& translate);

    Vector3 GetTranslation() const;

    /// <returns>逆行列</returns>
    Matrix4x4 Inverse() const;

    /// <returns>転置行列</returns>
    Matrix4x4 Transpose() const;

    Matrix4x4& operator+=(const Matrix4x4& rm);
    Matrix4x4& operator-=(const Matrix4x4& rm);
    Matrix4x4& operator*=(const Matrix4x4& rm);
    Matrix4x4 operator*(const Matrix4x4& rm) const;
    Matrix4x4 operator+(const Matrix4x4& rm) const;
    Matrix4x4 operator-(const Matrix4x4& rm) const;
};