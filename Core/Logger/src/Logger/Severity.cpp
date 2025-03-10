#include "pch.h"
#include "Severity.h"

/** 
 * - [ToString] : [Fonction qui renvoi un nom en fonction du type de Log]. 
 * 
* @Description : 
* [La fonction doit ici pourvoir renvoyer un nom que l'on chois d'attribuer en fonction du 
* type de Log, ceci permet de pouvoir precisé plus clairement un quel est le type de Log et le transformer en chaine 
* de caractère pour être affiché à l'écran]. 
* 
* @param ([Severity]) [severity] : [le type de Log]. 
* ... 
* @return ([string]) : [Un texte qui précise la nature du Log]. 
*/
const std::string ToString(Severity severity){
    if (severity == Severity::Severity_Info) return "Info";
    if (severity == Severity::Severity_Assert) return "Assert";
    if (severity == Severity::Severity_Trace) return "Trace";
    if (severity == Severity::Severity_Error) return "Error";
    if (severity == Severity::Severity_Debug) return "Debug";
    if (severity == Severity::Severity_Warning) return "Warning";
    if (severity == Severity::Severity_Critical) return "Critical";
    if (severity == Severity::Severity_Fatal) return "Fatal";

    return "Trace";
}

/** 
 * - [FromString] : [Fonction qui renvoi un type de Log en fonction de son nom]. 
 * 
* @Description : 
* [La fonction doit ici pourvoir recuperer un nom de log et renvoyer son type, 
* ceci sera utile dans l'analyse de Log]. 
* 
* @param ([std::string]) [type] : [Un texte qui précise la nature du Log]. 
* ... 
* @return ([Severity]) : [Le type de Log]. 
*/
Severity FromString(const std::string& type){
    if (type == "Info") return Severity::Severity_Info;
    if (type == "Assert") return Severity::Severity_Assert;
    if (type == "Trace") return Severity::Severity_Trace;
    if (type == "Error") return Severity::Severity_Error;
    if (type == "Debug") return Severity::Severity_Debug;
    if (type == "Warning") return Severity::Severity_Warning;
    if (type == "Critical") return Severity::Severity_Critical;
    if (type == "Fatal") return Severity::Severity_Fatal;

    return Severity::Severity_Default;
}