#ifndef MATERIAL_H
#define MATERIAL_H

#include <QImage>
#include <QString>
#include <QVector3D>


class Material
{
public:
    Material() {}

    QString getName();
    void setName(const QString &n);

    QVector3D getDiffuseColor() const;
    void setDiffuseColor(const QVector3D &dc);

    QVector3D getAmbienceColor() const;
    void setAmbienceColor(const QVector3D &ac);

    QVector3D getSpecularColor() const;
    void setSpecularColor(const QVector3D &sc);

    float getShines() const;
    void setShines(const float &s);

    QImage getDiffuseMap() const;
    void setDiffuseMap(const QString &filename);
     void setDiffuseMap(const QImage &image);

private:
    QString m_MtlName;
    QVector3D m_DiffuseColor;
    QVector3D m_AmbienceColor;
    QVector3D m_SpecularColor;
    float m_Shines;
    QImage m_DiffuseMap;
};

#endif // MATERIAL_H
