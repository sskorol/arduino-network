#include "Helpers.hpp"

namespace Helpers {
    IPAddress toIP(const String &ipAddress) {
        IPAddress ip;
        return !ip.fromString(ipAddress) ? IPAddress(127, 0, 0, 1) : ip;
    }
}  // namespace Helpers
