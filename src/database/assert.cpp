#include <avm-editor/database/assert.hpp>
#include <QtDebug>

#ifdef SQLITECPP_ENABLE_ASSERT_HANDLER
namespace SQLite {
/// \brief Definition of the assertion handler.
void assertion_failed(const char *apFile,
                      const long apLine,
                      const char *apFunc,
                      const char *apExpr,
                      const char *apMsg)
{
    // Print a message to the critical error output stream
    qCritical() << apFile << ":" << apLine << ":"
                << " error: assertion failed (" << apExpr << ") in " << apFunc
                << "() with message \"" << apMsg << "\"\n";
}
} // namespace SQLite
#endif
