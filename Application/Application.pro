QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        bogie.cpp \
        customer.cpp \
        linked_bogies.cpp \
        linked_bogies_empty_exception.cpp \
        linked_bogies_invalid_argument_exception.cpp \
        linked_bogies_out_of_range_exception.cpp \
        member.cpp \
        node.cpp \
        party_member.cpp \
        run.cpp \
        validation.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
  bogie.h \
  customer.h \
  linked_bogies.h \
  linked_bogies_empty_exception.h \
  linked_bogies_invalid_argument_exception.h \
  linked_bogies_out_of_range_exception.h \
  member.h \
  node.h \
  party_member.h \
  validation.h

DISTFILES += \
  README.md
