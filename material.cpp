#include "material.h"


QString Material::Name()
{
   return m_Name;
}

void Material::setName(const QString &n)
{
   m_Name = n;
}

QVector3D Material::DiffuseColor() const
{
    return m_DiffuseColor;
}

void Material::setDiffuseColor(const QVector3D &dc)
{
    m_DiffuseColor = dc;
}

QVector3D Material::AmbienceColor() const
{
    return m_AmbienceColor;
}

void Material::setAmbienceColor(const QVector3D &ac)
{
    m_AmbienceColor = ac;
}

QVector3D Material::SpecularColor() const
{
    return m_SpecularColor;
}

void Material::setSpecularColor(const QVector3D &sc)
{
    m_SpecularColor = sc;
}

float Material::Shines() const
{
    return m_Shines;
}

void Material::setShines(const float &s)
{
    m_Shines = s;
}

QImage Material::DiffuseMap() const
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
