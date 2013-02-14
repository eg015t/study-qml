/*
 * FileSystemModel.cpp
 *
 *  Created on: 13.02.2013
 *      Author: Dmitry
 */

#include "FileSystemModel.h"

FileSystemModel::FileSystemModel(QObject* parent):
  QFileSystemModel(parent)
{
  setFilter(QDir::Files | QDir::AllDirs);
}

QString FileSystemModel::rootPath()const
{
  return QFileSystemModel::rootPath();

}

void FileSystemModel::setRootPath(const QString& path)
{
  QFileSystemModel::setRootPath(path);
  emit rootPathChanged();
}

QModelIndex FileSystemModel::indexFromPath(const QString & path, int column ) const
{
  return QFileSystemModel::index(path, column);
}

QString FileSystemModel::fileName(const QModelIndex & index) const
{
  return QFileSystemModel::fileName(index);
}
QString FileSystemModel::filePath(const QModelIndex & index) const
{
  return QFileSystemModel::filePath(index);
}

bool FileSystemModel::isDir(const QString& path) const
{
    return QFileSystemModel::isDir(index(path));
}

QModelIndex FileSystemModel::parentIndex(const QModelIndex& child) const
{
  return QFileSystemModel::parent(child);
}
