TEMPLATE = app

TARGET = tst_scene2d

QT += 3dcore 3dcore-private 3drender 3drender-private testlib 3dquickrender 3dquickrender-private

CONFIG += testcase

SOURCES += tst_scene2d.cpp

include(../../core/common/common.pri)
include(../commons/commons.pri)
