TEMPLATE = app

TARGET = tst_qanimationclip

QT += 3dcore 3dcore-private 3danimation 3danimation-private testlib

CONFIG += testcase

SOURCES += \
    tst_qanimationclip.cpp

include(../../core/common/common.pri)
