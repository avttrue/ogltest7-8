#include "materiallibrary.h"
#include "material.h"

#include <QDebug>
#include <QDir>

MaterialLibrary::MaterialLibrary()
{

}

bool MaterialLibrary::loadFromFile(const QString &path)
{
    QFile objfile(path);

    if(! objfile.exists()) { qCritical() << "File not exist:" << path; return false; }
    if(! objfile.open(QFile::ReadOnly))  { qCritical() << "File not opened:" << path; return false; }

    for(auto o: m_Materials) delete o;
    m_Materials.clear();

    QFileInfo fi(path);
    QString apath = fi.absolutePath() + QDir::separator();
    Material* newMtl = nullptr;

    QTextStream input(&objfile);
    qDebug() << "Reading" << path << "...";

    bool ok = true;
    while(!input.atEnd())
    {
        auto str = input.readLine(); if(str.isEmpty()) continue;
        auto strlist = str.split(' '); strlist.removeAll("");
        auto key = strlist.at(0);

        if (key == "#") { qDebug() << str; }
        else if(key == "newmtl")
        {
            add(newMtl);
            newMtl = new Material();
            if(strlist.size() > 1) newMtl->setName(strlist.at(1));
            else
            {
                newMtl->setName(QString::number(m_Materials.size()));
                qCritical() << "Error at line (material name not present):" << str;
            }
        }
        else if(newMtl && key.toLower() == "ns")
        {
            if(strlist.size() > 1) newMtl->setShines(strlist.at(1).toFloat(&ok));
            else { qCritical() << "Error at line (count):" << str; ok = false; }
        }
        else if(newMtl && key.toLower() == "ka")
        {
            if(strlist.size() > 3)
            {
                newMtl->setAmbienceColor(QVector3D(strlist.at(1).toFloat(&ok),
                                                   strlist.at(2).toFloat(&ok),
                                                   strlist.at(3).toFloat(&ok)));
                if(!ok) { qCritical() << "Error at line (format):" << str; }
            }
            else { qCritical() << "Error at line (count):" << str; ok = false; }
        }
        else if(newMtl && key.toLower() == "kd")
        {
            if(strlist.size() > 3)
            {
                newMtl->setDiffuseColor(QVector3D(strlist.at(1).toFloat(&ok),
                                                  strlist.at(2).toFloat(&ok),
                                                  strlist.at(3).toFloat(&ok)));
                if(!ok) { qCritical() << "Error at line (format):" << str; }
            }
            else { qCritical() << "Error at line (count):" << str; ok = false; }
        }
        else if(newMtl && key.toLower() == "ks")
        {
            if(strlist.size() > 3)
            {
                newMtl->setSpecularColor(QVector3D(strlist.at(1).toFloat(&ok),
                                                   strlist.at(2).toFloat(&ok),
                                                   strlist.at(3).toFloat(&ok)));
                if(!ok) { qCritical() << "Error at line (format):" << str; }
            }
            else { qCritical() << "Error at line (count):" << str; ok = false; }
        }
        else if(newMtl && key.toLower() == "ke")
        {
          qDebug() << str;
        }
        else if(newMtl && key.toLower() == "ni")
        {
          qDebug() << str;
        }
        else if(newMtl && key.toLower() == "d")
        {
          qDebug() << str;
        }
        else if(newMtl && key.toLower() == "illum")
        {
          qDebug() << str;
        }
        else if(newMtl && key.toLower() == "map_kd")
        {
            if(strlist.size() > 1)
            {
                newMtl->setDiffuseMap(apath + strlist.at(1));
            }
            else { qCritical() << "Error at line (count):" << str; ok = false; }
        }
        add(newMtl);
    }

    objfile.close();
    qDebug() << "... done";

    if(!ok) return false;
    qDebug() << "success";
    return true;
}

void MaterialLibrary::add(Material *m)
{
    if(!m) return;
    for(auto o: m_Materials) if(o == m) return;
    m_Materials.append(m);
}

Material *MaterialLibrary::get(int index)
{
    if(index > -1 && index < m_Materials.size()) return m_Materials.at(index);
    return nullptr;
}

Material *MaterialLibrary::get(const QString &name)
{
    for(auto o: m_Materials) if(o->getName() == name) return o;
    return nullptr;
}

int MaterialLibrary::count()
{
    return m_Materials.size();
}