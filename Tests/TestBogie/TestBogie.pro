QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../Application

SOURCES +=  \
  ../../Application/bogie.cpp \
  ../../Application/member.cpp \
  tst_bogie.cpp
