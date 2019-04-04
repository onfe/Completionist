#pragma once

#include <stdint.h>
#include "Phrase.hpp"

// Type declarations
typedef std::pair<uint32_t, uint32_t> uip_t;
typedef std::vector<uip_t> uipv_t;

typedef std::vector<phrase_t> pvc_t;
typedef pvc_t::iterator pvci_t;
typedef std::pair<pvci_t, pvci_t> pvcip_t;
