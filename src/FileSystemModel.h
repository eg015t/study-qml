/*
 * FileSystemModel.h
 *
 *  Created on: 13.02.2013
 *      Author: Dmitry
 */

#ifndef FILESYSTEMMODEL_H_
#define FILESYSTEMMODEL_H_

#include <QtWidgets/QFileSystemModel>

class FileSystemModel: public QFileSystemModel
{
  Q_OBJECT

  Q_PROPERTY(QString rootPath READ rootPath WRITE setRootPath NOTIFY rootPathChanged)
public:
  FileSystemModel(QObject* parent = 0);

  /*!
   * @brief получить корень
   */
  QString rootPath()const;

  /*!
   * @brief установить корень
   */
  void setRootPath(const QString& path);

  /*!
   * @brief обертка над QFileSystemModel::index
   */
  Q_INVOKABLE QModelIndex indexFromPath(const QString & path, int column = 0) const;

  Q_INVOKABLE QString fileName(const QModelIndex & index) const;
  Q_INVOKABLE QString filePath(const QModelIndex & index) const;

  /*!
   * @brief проверка на каталог
   */
  Q_INVOKABLE bool isDir(const QString& path) const;

  Q_INVOKABLE QModelIndex parentIndex(const QModelIndex& child) const;

signals:
  void rootPathChanged();

};

#endif /* FILESYSTEMMODEL_H_ */
