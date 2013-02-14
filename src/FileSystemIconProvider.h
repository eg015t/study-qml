/*
 * FileSystemIconProvider.h
 *
 *  Created on: 13.02.2013
 *      Author: Dmitry
 */

#ifndef FILESYSTEMICONPROVIDER_H_
#define FILESYSTEMICONPROVIDER_H_

#include <QtWidgets/QFileIconProvider>
#include <QtQuick/QQuickImageProvider>

/*!
 * @brief поставщик иконок
 */
class FileSystemIconProvider: public QQuickImageProvider
{
public:
  /*!
    \brief дефолтная длина
    */
  static const size_t DEFAULT_WIDTH  = 64;

  /*!
    \brief дефолтная высота
    */
  static const size_t DEFAULT_HEIGTH = 64;

  FileSystemIconProvider();

  virtual QPixmap requestPixmap(const QString & id, QSize * size, const QSize & requestedSize);

private:
  QFileIconProvider iconProvider_; //!< поставщик иконок fs

};

#endif /* FILESYSTEMICONPROVIDER_H_ */
