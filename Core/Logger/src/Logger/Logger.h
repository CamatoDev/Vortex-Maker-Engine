#ifndef __LOGGER_LOGGER_H__
#define __LOGGER_LOGGER_H__

#include <string>
#include <vector>
#include <memory>
#include <optional>
#include <source_location>

// Inclure les utilitaires
#include "Utilities.h"
#include "Core/Exports.h"

/**
 * @Enum LogLevel
 * @Description Définit les niveaux de log disponibles pour l'application.
 */
enum class CORE_API LogLevel { DEBUG, INFO, WARNING, ERROR, ASSERT };

/**
 * @Function LogLevelToString
 * @Description Convertit une valeur LogLevel en sa représentation textuelle.
 */
inline std::string CORE_API LogLevelToString(LogLevel level) {
    switch (level) {
        case LogLevel::DEBUG:   return "DEBUG";
        case LogLevel::INFO:    return "INFO";
        case LogLevel::WARNING: return "WARNING";
        case LogLevel::ERROR:   return "ERROR";
        case LogLevel::ASSERT:   return "ASSERT";
        default:                return "UNKNOWN";
    }
}

/**
 * @Function GetColorCode
 * @Description Retourne le code ANSI de couleur associé au niveau de log.
 */
inline std::string GetColorCode(LogLevel level) {
    switch (level) {
        case LogLevel::DEBUG:   return "\033[36m"; // Cyan
        case LogLevel::INFO:    return "\033[32m"; // Vert
        case LogLevel::WARNING: return "\033[33m"; // Jaune
        case LogLevel::ERROR:   return "\033[31m"; // Rouge
        case LogLevel::ASSERT:   return "\033[31m"; // Rouge
        default:                return "\033[0m";
    }
}

/**
 * @Interface LoggerTarget
 * @Description Interface pour les cibles de log. Chaque cible doit implémenter la méthode Log.
 */
class CORE_API LoggerTarget {
public:
    virtual ~LoggerTarget() {}
    virtual void Log(LogLevel level, const std::string& message,
                     const char* file, int line, const char* func,
                     const std::string& timestamp) = 0;
};

/**
 * @Class Logger
 * @Description Système de log centralisant plusieurs cibles (Console, File, GUI).
 */
class CORE_API Logger {
public:
    explicit Logger(const std::string& appName);
    void SetApplicationName(const std::string& appName);
    
    /**
     * @Function Source
     * @Description Stocke temporairement le contexte d'appel pour le prochain appel de log.
     * @Param (const std::source_location&) location : Contexte à stocker.
     * @Return (Logger&) : Référence pour chaîner les appels.
     */
    Logger& Source(const std::source_location& location = std::source_location::current());
    
    /**
     * @Function Log
     * @Description Enregistre un message de log en utilisant le contexte stocké via Source() (si défini),
     *              sinon en capturant automatiquement le contexte.
     */
    void Log(LogLevel level, const std::string& message,
             const std::source_location& defaultLocation = std::source_location::current());

    void LogAssertFalse(bool condition, const std::string& message,
             const std::source_location& defaultLocation = std::source_location::current());  
    
    void LogAssertTrue(bool condition, const std::string& message,
             const std::source_location& defaultLocation = std::source_location::current()); 

    void LogAssertEqual(float x, float y, const std::string& message,
             const std::source_location& defaultLocation = std::source_location::current()); 

    void LogAssertNull(float x, const std::string& message,
             const std::source_location& defaultLocation = std::source_location::current()); 
    
    template<typename... Args>
    void Debug(const std::string& fmt, const Args&... args) {
         Log(LogLevel::DEBUG, Format(fmt, args...), std::source_location::current());
    }
    
    template<typename... Args>
    void Info(const std::string& fmt, const Args&... args) {
         Log(LogLevel::INFO, Format(fmt, args...), std::source_location::current());
    }
    
    template<typename... Args>
    void Warning(const std::string& fmt, const Args&... args) {
         Log(LogLevel::WARNING, Format(fmt, args...), std::source_location::current());
    }
    
    template<typename... Args>
    void Error(const std::string& fmt, const Args&... args) {
         Log(LogLevel::ERROR, Format(fmt, args...), std::source_location::current());
    }

    template<typename... Args>
    void AssertFalse(bool condition, const std::string& fmt, const Args&... args) {
        LogAssertFalse(condition, Format(fmt, args...), std::source_location::current());
    }

    template<typename... Args>
    void AssertTrue(bool condition, const std::string& fmt, const Args&... args) {
        LogAssertTrue(condition, Format(fmt, args...), std::source_location::current());
    }

    template<typename... Args>
    void AssertNull(float x, const std::string& fmt, const Args&... args) {
        LogAssertNull(x, Format(fmt, args...), std::source_location::current());
    }

    template<typename... Args>
    void AssertEqual(float x, float y, const std::string& fmt, const Args&... args) {
        LogAssertEqual(x, y, Format(fmt, args...), std::source_location::current());
    }
    
    void AddTarget(std::unique_ptr<LoggerTarget> target);
    
private:
    std::string ApplicationName;
    std::vector<std::unique_ptr<LoggerTarget>> Targets;
    std::optional<std::source_location> mLocation;
};

#endif // __LOGGER_LOGGER_H__
