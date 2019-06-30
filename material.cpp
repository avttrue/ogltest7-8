#include "material.h"


QString Material::getName()
{
   return m_MtlName;
}

void Material::setName(const QString &n)
{
   m_MtlName = n;
}

QVector3D Material::getDiffuseColor() const
{
    return m_DiffuseColor;
}

void Material::setDiffuseColor(const QVector3D &dc)
{
    m_DiffuseColor = dc;
}

QVector3D Material::getAmbienceColor() const
{
    return m_AmbienceColor;
}

void Material::setAmbienceColor(const QVector3D &ac)
{
    m_AmbienceColor = ac;
}

QVector3D Material::getSpecularColor() const
{
    return m_SpecularColor;
}

void Material::setSpecularColor(const QVector3D &sc)
{
    m_SpecularColor = sc;
}

float Material::getShines() const
{
    return m_Shines;
}

void Material::setShines(const float &s)
{
    m_Shines = s;
}

QImage Material::getDiffuseMap() const
{
    return m_DiffuseMap;
}

void Material::setDiffuseMap(const QString &filename)
{
    m_DiffuseMap = QImage(filename);
}

void Material::setDiffuseMap(const QImage &image)
{
   m_DiffuseMap = image;
}
