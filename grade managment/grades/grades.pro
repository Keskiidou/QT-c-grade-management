QT       += core gui sql
QT       += printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    enseignant/enseignant.cpp \
    etudiant/etudiant.cpp \
    groupe/groupe.cpp \
    groupemodule/groupemodule.cpp \
    main.cpp \
    mainwindow/mainwindow.cpp \
    matiere/matiere.cpp \
    note/note.cpp \
    personne/personne.cpp


HEADERS += \
    enseignant/enseignant.h \
    etudiant/etudiant.h \
    groupe/groupe.h \
    groupe/pdfExport.h \
    groupemodule/groupemodule.h \
    mainwindow/mainwindow.h \
    matiere/matiere.h \
    note/note.h \
    personne/personne.h


FORMS += \
    enseignant/enseignant.ui \
    etudiant/etudiant.ui \
    groupe/Groupe_Gm_Etudiant.ui \
    groupe/groupe.ui \
    groupemodule/groupemodule.ui \
    mainwindow/mainwindow.ui \
    matiere/matiere.ui \
    note/note.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
