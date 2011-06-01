#include "ELFSectionSymTabEntry.h"

#include <elf.h>

char const *
ELFSectionSymTabEntryHelperMixin::getTypeStr(uint8_t type) {
  switch (type) {
    default: return "(UNKNOWN)";

#define CASE(TYPE) \
    case STT_##TYPE: return #TYPE;

    CASE(NOTYPE)
    CASE(OBJECT)
    CASE(FUNC)
    CASE(SECTION)
    CASE(FILE)
    CASE(COMMON)
    CASE(TLS)
    CASE(LOOS)
    CASE(HIOS)
    CASE(LOPROC)
    CASE(HIPROC)

#undef CASE
  }
}

char const *
ELFSectionSymTabEntryHelperMixin::getBindingAttributeStr(uint8_t type) {
  switch (type) {
    default: return "(UNKNOWN)";

#define CASE(TYPE) \
    case STB_##TYPE: return #TYPE;

    CASE(LOCAL)
    CASE(GLOBAL)
    CASE(WEAK)
    CASE(LOOS)
    CASE(HIOS)
    CASE(LOPROC)
    CASE(HIPROC)

#undef CASE
  }
}
char const *
ELFSectionSymTabEntryHelperMixin::getVisibilityStr(uint8_t type) {
  switch (type) {
    default: return "(UNKNOWN)";

#define CASE(TYPE) \
    case STV_##TYPE: return #TYPE;

    CASE(DEFAULT)
    CASE(INTERNAL)
    CASE(HIDDEN)
    CASE(PROTECTED)

#undef CASE
  }
}