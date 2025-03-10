#include "pch.h"
#include "Logger.h"
#include "Windows.h"

#include <iostream>

// Variable pour la couleur par defaut de l'affichage dans la console.
int defaultColor = 7;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

Logger::Logger() {
}
Logger::Logger(const std::string& name){

}
const std::string& Logger::GetName() const{
    return "";
}
void Logger::SetName(const std::string& name){

}

Logger& Logger::Details(const char* file, unsigned int ligne, const char* function){
    return *this;
}


/** 
* - [PreWrite] : [fonction pour l'ecriture des différents messages log]. 
* 
* @Description : [Cette methode vas récuperer le type de message de log pour et lui affecté une couleur être precisé
*  en début ainsi que message qui sera mis au format prevu avant d'être affiché par la suite.]
* @param ([Severity]) [severity] : [le type du message de log].
* @param ([string]) [message] : [Le message qui sera affiché après le type de log]. 
*/ 
void Logger::PreWrite(Severity severity, const std::string& message){
    if (severity == Severity::Severity_Info)
        SetConsoleTextAttribute(h, 1);
    if (severity == Severity::Severity_Assert)
        SetConsoleTextAttribute(h, 8);
    if (severity == Severity::Severity_Trace)
        SetConsoleTextAttribute(h, 7);
    if (severity == Severity::Severity_Error)
        SetConsoleTextAttribute(h, 12);
    if (severity == Severity::Severity_Debug)
        SetConsoleTextAttribute(h, 15);
    if (severity == Severity::Severity_Warning)
        SetConsoleTextAttribute(h, 14);
    if (severity == Severity::Severity_Critical)
        SetConsoleTextAttribute(h, 4);
    if (severity == Severity::Severity_Fatal)
        SetConsoleTextAttribute(h, 4);
    // Ecriture du message au format [severity] :    message.
    std::cout << "[" << ToString(severity) << "] :  " << message << "." << "\n";
    // Retour à la couleur d'affichage par defaut
    SetConsoleTextAttribute(h, defaultColor);
}