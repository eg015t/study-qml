/*
 * FileSystemIconProvider.cpp
 *
 *  Created on: 13.02.2013
 *      Author: Dmitry
 */


#include "FileSystemIconProvider.h"

FileSystemIconProvider::FileSystemIconProvider():
  QQuickImageProvider(QQmlImageProviderBase::Pixmap)
{
}

QPixmap FileSystemIconProvider::requestPixmap(const QString & id, QSize * size, const QSize & requestedSize)
{
  *size = QSize(DEFAULT_WIDTH, DEFAULT_HEIGTH);

  QIcon icon = iconProvider_.icon(id);

  return icon.pixmap( requestedSize.isValid() ? requestedSize :  *size);
}
