#include <boost/format.hpp>
#include <sstream>

#pragma once

#define PRIVACY_NOTIFICATION(MSG) \
 	MGINFO_CYAN(boost::format("User connecting from %1%:") % ctx->m_remote_address.str()); \
	MGINFO_CYAN(boost::format MSG)

#define GET_BLOCK_HEADER_BY_HASH() PRIVACY_NOTIFICATION(GET_BLOCK_HEADER_BY_HASH_MSG)
#define GET_BLOCK_HEADER_BY_HEIGHT() PRIVACY_NOTIFICATION(GET_BLOCK_HEADER_BY_HEIGHT_MSG)
#define GET_BLOCK_HEADERS_RANGE() PRIVACY_NOTIFICATION(GET_BLOCK_HEADERS_RANGE_MSG)
#define GET_OUTPUT_HISTOGRAM() PRIVACY_NOTIFICATION(GET_OUTPUT_HISTOGRAM_MSG)
#define RELAY_TX() PRIVACY_NOTIFICATION(RELAY_TX_MSG)
#define GET_O_INDEXES_BIN() PRIVACY_NOTIFICATION(GET_O_INDEXES_BIN_MSG)
#define IS_KEY_IMAGE_SPENT() PRIVACY_NOTIFICATION(IS_KEY_IMAGE_SPENT_MSG)
#define SEND_RAW_TRANSACTION() PRIVACY_NOTIFICATION(SEND_RAW_TRANSACTION_MSG)
#define GET_TRANSACTIONS() PRIVACY_NOTIFICATION(GET_TRANSACTIONS_MSG)

#define GET_BLOCK_HEADER_BY_HASH_MSG ("accessed header of block with hash: ").str() + stream_to_str(req.hash)
#define GET_BLOCK_HEADER_BY_HEIGHT_MSG ("accessed header of block with height: %1%") % req.height
#define GET_BLOCK_HEADERS_RANGE_MSG ("accessed header of blocks in range: %1%, %2%") % req.start_height % req.end_height
#define GET_OUTPUT_HISTOGRAM_MSG ("searched with outputs of amount: ").str() + vec_to_string(req.amounts)
#define RELAY_TX_MSG ("attempted to relay transactions with id's: ").str() + vec_to_string(req.txids)
#define GET_O_INDEXES_BIN_MSG ("requested ouputs of transaction with id: %1%") % req.txid
#define IS_KEY_IMAGE_SPENT_MSG ("checked if outputs associated key images: spent these key images ").str() + vec_to_string(req.key_images)
#define SEND_RAW_TRANSACTION_MSG ("broadcatsed to the network transaction: %1%") % req.tx_as_hex
#define GET_TRANSACTIONS_MSG ("requested transactions with hashes: ").str() + vec_to_string(req.txs_hashes)
 
template <typename T>
std::string vec_to_string(std::vector<T> vec) {
	std::ostringstream s;
	int i = 0;
	for (T x: vec) {
		s << x << "\n";
		i ++;
		if (i > 8) {
			s << boost::format("(ommitting %1\% items for brevity)") % (vec.size() - 8);
			break;
		}
	}
	return s.str();
}

template <typename T>
std::string stream_to_str(T x) {
	std::ostringstream s;
	s << x;
	return s.str();
}
