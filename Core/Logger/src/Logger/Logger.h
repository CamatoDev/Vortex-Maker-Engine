#ifndef __LOGGER_LOGGER_H__
#define __LOGGER_LOGGER_H__

#include <functional>
#include "Severity.h"

    class  Logger {
    public:
        Logger();
        Logger(const std::string& name);
        virtual ~Logger() = default;
        const std::string& GetName() const;
        void SetName(const std::string& name);

        Logger& Details(const char* file, unsigned int ligne, const char* function);

        /** 
        * - [Log] : [Il s'agit de la méthode qui vas permettre l'affichage du log avec le format choisi]. 
        * 
        * @param ([Severity]) [severity] : [Le type de log]. 
        * @param ([char*]) [format] : [Le format d'écriture]. 
        */
        void Log(Severity severity, const char* format = "") {
            PreWrite(severity, format);
        }

        // Specific log methods for different severity levels
        template<typename... Args>
        void Info(const char* format = "", Args&&... args) {
            Log(Severity::Severity_Info, format, args...);
        }

        template<typename... Args>
        void Assert(const char* format = "", Args&&... args) {
            Log(Severity::Severity_Assert, format, args...);
        }

        template<typename... Args>
        void Error(const char* format = "", Args&&... args) {
            Log(Severity::Severity_Error, format, args...);
        }

        template<typename... Args>
        void Warning(const char* format = "", Args&&... args) {
            Log(Severity::Severity_Warning, format, args...);
        }

        template<typename... Args>
        void Debug(const char* format = "", Args&&... args) {
            Log(Severity::Severity_Debug, format, args...);
        }

        template<typename... Args>
        void Trace(const char* format = "", Args&&... args) {
            Log(Severity::Severity_Trace, format, args...);
        }

        template<typename... Args>
        void Critical(const char* format = "", Args&&... args) {
            Log(Severity::Severity_Critical, format, args...);
        }

        template<typename... Args>
        void Fatal(const char* format = "", Args&&... args) {
            Log(Severity::Severity_Fatal, format, args...);
        }

    private:
    /** 
    * - [PreWrite] : [fonction pour l'ecriture des différents messages log]. 
    * 
    * @Description : [Cette methode vas récuperer le type de message de log pour et lui affecté une couleur être precisé
    *  en début ainsi que message qui sera mis au format prevu avant d'être affiché par la suite.]
    * @param ([Severity]) [severity] : [le type du message de log].
    * @param ([string]) [message] : [Le message qui sera affiché après le type de log]. 
    */ 
        void PreWrite(Severity Severity, const std::string& message);
    };

#endif  // __LOGGER_LOGGER_H__"