/* This file was generated by generate-wire.py */
/* Do not modify this file! Modify the .csv file it was generated from. */
/* Original template can be found at tools/gen/impl_template */

#include <gossipd/gossipd_wiregen.h>
#include <assert.h>
#include <ccan/array_size/array_size.h>
#include <ccan/mem/mem.h>
#include <ccan/tal/str/str.h>
#include <common/utils.h>
#include <stdio.h>

#ifndef SUPERVERBOSE
#define SUPERVERBOSE(...)
#endif


const char *gossipd_wire_name(int e)
{
	static char invalidbuf[sizeof("INVALID ") + STR_MAX_CHARS(e)];

	switch ((enum gossipd_wire)e) {
	case WIRE_GOSSIPD_INIT: return "WIRE_GOSSIPD_INIT";
	case WIRE_GOSSIPD_INIT_REPLY: return "WIRE_GOSSIPD_INIT_REPLY";
	case WIRE_GOSSIPD_DEV_SET_TIME: return "WIRE_GOSSIPD_DEV_SET_TIME";
	case WIRE_GOSSIPD_PING: return "WIRE_GOSSIPD_PING";
	case WIRE_GOSSIPD_PING_REPLY: return "WIRE_GOSSIPD_PING_REPLY";
	case WIRE_GOSSIPD_DEV_SET_MAX_SCIDS_ENCODE_SIZE: return "WIRE_GOSSIPD_DEV_SET_MAX_SCIDS_ENCODE_SIZE";
	case WIRE_GOSSIPD_GET_STRIPPED_CUPDATE: return "WIRE_GOSSIPD_GET_STRIPPED_CUPDATE";
	case WIRE_GOSSIPD_GET_STRIPPED_CUPDATE_REPLY: return "WIRE_GOSSIPD_GET_STRIPPED_CUPDATE_REPLY";
	case WIRE_GOSSIPD_LOCAL_CHANNEL_CLOSE: return "WIRE_GOSSIPD_LOCAL_CHANNEL_CLOSE";
	case WIRE_GOSSIPD_GET_TXOUT: return "WIRE_GOSSIPD_GET_TXOUT";
	case WIRE_GOSSIPD_GET_TXOUT_REPLY: return "WIRE_GOSSIPD_GET_TXOUT_REPLY";
	case WIRE_GOSSIPD_OUTPOINT_SPENT: return "WIRE_GOSSIPD_OUTPOINT_SPENT";
	case WIRE_GOSSIPD_DEV_SUPPRESS: return "WIRE_GOSSIPD_DEV_SUPPRESS";
	case WIRE_GOSSIPD_DEV_MEMLEAK: return "WIRE_GOSSIPD_DEV_MEMLEAK";
	case WIRE_GOSSIPD_DEV_MEMLEAK_REPLY: return "WIRE_GOSSIPD_DEV_MEMLEAK_REPLY";
	case WIRE_GOSSIPD_DEV_COMPACT_STORE: return "WIRE_GOSSIPD_DEV_COMPACT_STORE";
	case WIRE_GOSSIPD_DEV_COMPACT_STORE_REPLY: return "WIRE_GOSSIPD_DEV_COMPACT_STORE_REPLY";
	case WIRE_GOSSIPD_NEW_BLOCKHEIGHT: return "WIRE_GOSSIPD_NEW_BLOCKHEIGHT";
	case WIRE_GOSSIPD_GOT_ONIONMSG_TO_US: return "WIRE_GOSSIPD_GOT_ONIONMSG_TO_US";
	case WIRE_GOSSIPD_GOT_ONIONMSG_FORWARD: return "WIRE_GOSSIPD_GOT_ONIONMSG_FORWARD";
	case WIRE_GOSSIPD_SEND_ONIONMSG: return "WIRE_GOSSIPD_SEND_ONIONMSG";
	case WIRE_GOSSIPD_ADDGOSSIP: return "WIRE_GOSSIPD_ADDGOSSIP";
	case WIRE_GOSSIPD_ADDGOSSIP_REPLY: return "WIRE_GOSSIPD_ADDGOSSIP_REPLY";
	case WIRE_GOSSIPD_NEW_LEASE_RATES: return "WIRE_GOSSIPD_NEW_LEASE_RATES";
	}

	snprintf(invalidbuf, sizeof(invalidbuf), "INVALID %i", e);
	return invalidbuf;
}

bool gossipd_wire_is_defined(u16 type)
{
	switch ((enum gossipd_wire)type) {
	case WIRE_GOSSIPD_INIT:;
	case WIRE_GOSSIPD_INIT_REPLY:;
	case WIRE_GOSSIPD_DEV_SET_TIME:;
	case WIRE_GOSSIPD_PING:;
	case WIRE_GOSSIPD_PING_REPLY:;
	case WIRE_GOSSIPD_DEV_SET_MAX_SCIDS_ENCODE_SIZE:;
	case WIRE_GOSSIPD_GET_STRIPPED_CUPDATE:;
	case WIRE_GOSSIPD_GET_STRIPPED_CUPDATE_REPLY:;
	case WIRE_GOSSIPD_LOCAL_CHANNEL_CLOSE:;
	case WIRE_GOSSIPD_GET_TXOUT:;
	case WIRE_GOSSIPD_GET_TXOUT_REPLY:;
	case WIRE_GOSSIPD_OUTPOINT_SPENT:;
	case WIRE_GOSSIPD_DEV_SUPPRESS:;
	case WIRE_GOSSIPD_DEV_MEMLEAK:;
	case WIRE_GOSSIPD_DEV_MEMLEAK_REPLY:;
	case WIRE_GOSSIPD_DEV_COMPACT_STORE:;
	case WIRE_GOSSIPD_DEV_COMPACT_STORE_REPLY:;
	case WIRE_GOSSIPD_NEW_BLOCKHEIGHT:;
	case WIRE_GOSSIPD_GOT_ONIONMSG_TO_US:;
	case WIRE_GOSSIPD_GOT_ONIONMSG_FORWARD:;
	case WIRE_GOSSIPD_SEND_ONIONMSG:;
	case WIRE_GOSSIPD_ADDGOSSIP:;
	case WIRE_GOSSIPD_ADDGOSSIP_REPLY:;
	case WIRE_GOSSIPD_NEW_LEASE_RATES:;
	      return true;
	}
	return false;
}





/* WIRE: GOSSIPD_INIT */
/* Initialize the gossip daemon. */
u8 *towire_gossipd_init(const tal_t *ctx, const struct chainparams *chainparams, const struct feature_set *our_features, const struct node_id *id, const u8 rgb[3], const u8 alias[32], const struct wireaddr *announcable, u32 *dev_gossip_time, bool dev_fast_gossip, bool dev_fast_gossip_prune)
{
	u16 num_announcable = tal_count(announcable);
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_GOSSIPD_INIT);
	towire_chainparams(&p, chainparams);
	towire_feature_set(&p, our_features);
	towire_node_id(&p, id);
	towire_u8_array(&p, rgb, 3);
	towire_u8_array(&p, alias, 32);
	towire_u16(&p, num_announcable);
	for (size_t i = 0; i < num_announcable; i++)
		towire_wireaddr(&p, announcable + i);
	if (!dev_gossip_time)
		towire_bool(&p, false);
	else {
		towire_bool(&p, true);
		towire_u32(&p, *dev_gossip_time);
	}
	towire_bool(&p, dev_fast_gossip);
	towire_bool(&p, dev_fast_gossip_prune);

	return memcheck(p, tal_count(p));
}
bool fromwire_gossipd_init(const tal_t *ctx, const void *p, const struct chainparams **chainparams, struct feature_set **our_features, struct node_id *id, u8 rgb[3], u8 alias[32], struct wireaddr **announcable, u32 **dev_gossip_time, bool *dev_fast_gossip, bool *dev_fast_gossip_prune)
{
	u16 num_announcable;

	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_GOSSIPD_INIT)
		return false;
 	fromwire_chainparams(&cursor, &plen, chainparams);
 	*our_features = fromwire_feature_set(ctx, &cursor, &plen);
 	fromwire_node_id(&cursor, &plen, id);
 	fromwire_u8_array(&cursor, &plen, rgb, 3);
 	fromwire_u8_array(&cursor, &plen, alias, 32);
 	num_announcable = fromwire_u16(&cursor, &plen);
 	// 2nd case announcable
	*announcable = num_announcable ? tal_arr(ctx, struct wireaddr, num_announcable) : NULL;
	for (size_t i = 0; i < num_announcable; i++)
		fromwire_wireaddr(&cursor, &plen, *announcable + i);
 	if (!fromwire_bool(&cursor, &plen))
		*dev_gossip_time = NULL;
	else {
		*dev_gossip_time = tal(ctx, u32);
		**dev_gossip_time = fromwire_u32(&cursor, &plen);
	}
 	*dev_fast_gossip = fromwire_bool(&cursor, &plen);
 	*dev_fast_gossip_prune = fromwire_bool(&cursor, &plen);
	return cursor != NULL;
}

/* WIRE: GOSSIPD_INIT_REPLY */
u8 *towire_gossipd_init_reply(const tal_t *ctx)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_GOSSIPD_INIT_REPLY);

	return memcheck(p, tal_count(p));
}
bool fromwire_gossipd_init_reply(const void *p)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_GOSSIPD_INIT_REPLY)
		return false;
	return cursor != NULL;
}

/* WIRE: GOSSIPD_DEV_SET_TIME */
/* In developer mode */
u8 *towire_gossipd_dev_set_time(const tal_t *ctx, u32 dev_gossip_time)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_GOSSIPD_DEV_SET_TIME);
	towire_u32(&p, dev_gossip_time);

	return memcheck(p, tal_count(p));
}
bool fromwire_gossipd_dev_set_time(const void *p, u32 *dev_gossip_time)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_GOSSIPD_DEV_SET_TIME)
		return false;
 	*dev_gossip_time = fromwire_u32(&cursor, &plen);
	return cursor != NULL;
}

/* WIRE: GOSSIPD_PING */
/* Ping/pong test.  Waits for a reply if it expects one. */
u8 *towire_gossipd_ping(const tal_t *ctx, const struct node_id *id, u16 num_pong_bytes, u16 len)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_GOSSIPD_PING);
	towire_node_id(&p, id);
	towire_u16(&p, num_pong_bytes);
	towire_u16(&p, len);

	return memcheck(p, tal_count(p));
}
bool fromwire_gossipd_ping(const void *p, struct node_id *id, u16 *num_pong_bytes, u16 *len)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_GOSSIPD_PING)
		return false;
 	fromwire_node_id(&cursor, &plen, id);
 	*num_pong_bytes = fromwire_u16(&cursor, &plen);
 	*len = fromwire_u16(&cursor, &plen);
	return cursor != NULL;
}

/* WIRE: GOSSIPD_PING_REPLY */
u8 *towire_gossipd_ping_reply(const tal_t *ctx, const struct node_id *id, bool sent, u16 totlen)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_GOSSIPD_PING_REPLY);
	towire_node_id(&p, id);
	/* False if id in gossip_ping was unknown. */
	towire_bool(&p, sent);
	/* 0 == no pong expected */
	towire_u16(&p, totlen);

	return memcheck(p, tal_count(p));
}
bool fromwire_gossipd_ping_reply(const void *p, struct node_id *id, bool *sent, u16 *totlen)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_GOSSIPD_PING_REPLY)
		return false;
 	fromwire_node_id(&cursor, &plen, id);
 	/* False if id in gossip_ping was unknown. */
	*sent = fromwire_bool(&cursor, &plen);
 	/* 0 == no pong expected */
	*totlen = fromwire_u16(&cursor, &plen);
	return cursor != NULL;
}

/* WIRE: GOSSIPD_DEV_SET_MAX_SCIDS_ENCODE_SIZE */
/* Set artificial maximum reply_channel_range size.  Master->gossipd */
u8 *towire_gossipd_dev_set_max_scids_encode_size(const tal_t *ctx, u32 max)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_GOSSIPD_DEV_SET_MAX_SCIDS_ENCODE_SIZE);
	towire_u32(&p, max);

	return memcheck(p, tal_count(p));
}
bool fromwire_gossipd_dev_set_max_scids_encode_size(const void *p, u32 *max)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_GOSSIPD_DEV_SET_MAX_SCIDS_ENCODE_SIZE)
		return false;
 	*max = fromwire_u32(&cursor, &plen);
	return cursor != NULL;
}

/* WIRE: GOSSIPD_GET_STRIPPED_CUPDATE */
/* Given a short_channel_id */
u8 *towire_gossipd_get_stripped_cupdate(const tal_t *ctx, const struct short_channel_id *channel_id)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_GOSSIPD_GET_STRIPPED_CUPDATE);
	towire_short_channel_id(&p, channel_id);

	return memcheck(p, tal_count(p));
}
bool fromwire_gossipd_get_stripped_cupdate(const void *p, struct short_channel_id *channel_id)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_GOSSIPD_GET_STRIPPED_CUPDATE)
		return false;
 	fromwire_short_channel_id(&cursor, &plen, channel_id);
	return cursor != NULL;
}

/* WIRE: GOSSIPD_GET_STRIPPED_CUPDATE_REPLY */
u8 *towire_gossipd_get_stripped_cupdate_reply(const tal_t *ctx, const u8 *stripped_update)
{
	u16 stripped_update_len = tal_count(stripped_update);
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_GOSSIPD_GET_STRIPPED_CUPDATE_REPLY);
	towire_u16(&p, stripped_update_len);
	towire_u8_array(&p, stripped_update, stripped_update_len);

	return memcheck(p, tal_count(p));
}
bool fromwire_gossipd_get_stripped_cupdate_reply(const tal_t *ctx, const void *p, u8 **stripped_update)
{
	u16 stripped_update_len;

	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_GOSSIPD_GET_STRIPPED_CUPDATE_REPLY)
		return false;
 	stripped_update_len = fromwire_u16(&cursor, &plen);
 	// 2nd case stripped_update
	*stripped_update = stripped_update_len ? tal_arr(ctx, u8, stripped_update_len) : NULL;
	fromwire_u8_array(&cursor, &plen, *stripped_update, stripped_update_len);
	return cursor != NULL;
}

/* WIRE: GOSSIPD_LOCAL_CHANNEL_CLOSE */
/* gossipd->master: we're closing this channel. */
u8 *towire_gossipd_local_channel_close(const tal_t *ctx, const struct short_channel_id *short_channel_id)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_GOSSIPD_LOCAL_CHANNEL_CLOSE);
	towire_short_channel_id(&p, short_channel_id);

	return memcheck(p, tal_count(p));
}
bool fromwire_gossipd_local_channel_close(const void *p, struct short_channel_id *short_channel_id)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_GOSSIPD_LOCAL_CHANNEL_CLOSE)
		return false;
 	fromwire_short_channel_id(&cursor, &plen, short_channel_id);
	return cursor != NULL;
}

/* WIRE: GOSSIPD_GET_TXOUT */
/* Gossipd->master get this tx output please. */
u8 *towire_gossipd_get_txout(const tal_t *ctx, const struct short_channel_id *short_channel_id)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_GOSSIPD_GET_TXOUT);
	towire_short_channel_id(&p, short_channel_id);

	return memcheck(p, tal_count(p));
}
bool fromwire_gossipd_get_txout(const void *p, struct short_channel_id *short_channel_id)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_GOSSIPD_GET_TXOUT)
		return false;
 	fromwire_short_channel_id(&cursor, &plen, short_channel_id);
	return cursor != NULL;
}

/* WIRE: GOSSIPD_GET_TXOUT_REPLY */
/* master->gossipd here is the output */
u8 *towire_gossipd_get_txout_reply(const tal_t *ctx, const struct short_channel_id *short_channel_id, struct amount_sat satoshis, const u8 *outscript)
{
	u16 len = tal_count(outscript);
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_GOSSIPD_GET_TXOUT_REPLY);
	towire_short_channel_id(&p, short_channel_id);
	towire_amount_sat(&p, satoshis);
	towire_u16(&p, len);
	towire_u8_array(&p, outscript, len);

	return memcheck(p, tal_count(p));
}
bool fromwire_gossipd_get_txout_reply(const tal_t *ctx, const void *p, struct short_channel_id *short_channel_id, struct amount_sat *satoshis, u8 **outscript)
{
	u16 len;

	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_GOSSIPD_GET_TXOUT_REPLY)
		return false;
 	fromwire_short_channel_id(&cursor, &plen, short_channel_id);
 	*satoshis = fromwire_amount_sat(&cursor, &plen);
 	len = fromwire_u16(&cursor, &plen);
 	// 2nd case outscript
	*outscript = len ? tal_arr(ctx, u8, len) : NULL;
	fromwire_u8_array(&cursor, &plen, *outscript, len);
	return cursor != NULL;
}

/* WIRE: GOSSIPD_OUTPOINT_SPENT */
/* master -> gossipd: a potential funding outpoint was spent */
u8 *towire_gossipd_outpoint_spent(const tal_t *ctx, const struct short_channel_id *short_channel_id)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_GOSSIPD_OUTPOINT_SPENT);
	towire_short_channel_id(&p, short_channel_id);

	return memcheck(p, tal_count(p));
}
bool fromwire_gossipd_outpoint_spent(const void *p, struct short_channel_id *short_channel_id)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_GOSSIPD_OUTPOINT_SPENT)
		return false;
 	fromwire_short_channel_id(&cursor, &plen, short_channel_id);
	return cursor != NULL;
}

/* WIRE: GOSSIPD_DEV_SUPPRESS */
/* master -> gossipd: stop gossip timers. */
u8 *towire_gossipd_dev_suppress(const tal_t *ctx)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_GOSSIPD_DEV_SUPPRESS);

	return memcheck(p, tal_count(p));
}
bool fromwire_gossipd_dev_suppress(const void *p)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_GOSSIPD_DEV_SUPPRESS)
		return false;
	return cursor != NULL;
}

/* WIRE: GOSSIPD_DEV_MEMLEAK */
/* master -> gossipd: do you have a memleak? */
u8 *towire_gossipd_dev_memleak(const tal_t *ctx)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_GOSSIPD_DEV_MEMLEAK);

	return memcheck(p, tal_count(p));
}
bool fromwire_gossipd_dev_memleak(const void *p)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_GOSSIPD_DEV_MEMLEAK)
		return false;
	return cursor != NULL;
}

/* WIRE: GOSSIPD_DEV_MEMLEAK_REPLY */
u8 *towire_gossipd_dev_memleak_reply(const tal_t *ctx, bool leak)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_GOSSIPD_DEV_MEMLEAK_REPLY);
	towire_bool(&p, leak);

	return memcheck(p, tal_count(p));
}
bool fromwire_gossipd_dev_memleak_reply(const void *p, bool *leak)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_GOSSIPD_DEV_MEMLEAK_REPLY)
		return false;
 	*leak = fromwire_bool(&cursor, &plen);
	return cursor != NULL;
}

/* WIRE: GOSSIPD_DEV_COMPACT_STORE */
/* master -> gossipd: please rewrite the gossip_store */
u8 *towire_gossipd_dev_compact_store(const tal_t *ctx)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_GOSSIPD_DEV_COMPACT_STORE);

	return memcheck(p, tal_count(p));
}
bool fromwire_gossipd_dev_compact_store(const void *p)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_GOSSIPD_DEV_COMPACT_STORE)
		return false;
	return cursor != NULL;
}

/* WIRE: GOSSIPD_DEV_COMPACT_STORE_REPLY */
/* gossipd -> master: ok */
u8 *towire_gossipd_dev_compact_store_reply(const tal_t *ctx, bool success)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_GOSSIPD_DEV_COMPACT_STORE_REPLY);
	towire_bool(&p, success);

	return memcheck(p, tal_count(p));
}
bool fromwire_gossipd_dev_compact_store_reply(const void *p, bool *success)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_GOSSIPD_DEV_COMPACT_STORE_REPLY)
		return false;
 	*success = fromwire_bool(&cursor, &plen);
	return cursor != NULL;
}

/* WIRE: GOSSIPD_NEW_BLOCKHEIGHT */
/* master -> gossipd: blockheight increased. */
u8 *towire_gossipd_new_blockheight(const tal_t *ctx, u32 blockheight)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_GOSSIPD_NEW_BLOCKHEIGHT);
	towire_u32(&p, blockheight);

	return memcheck(p, tal_count(p));
}
bool fromwire_gossipd_new_blockheight(const void *p, u32 *blockheight)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_GOSSIPD_NEW_BLOCKHEIGHT)
		return false;
 	*blockheight = fromwire_u32(&cursor, &plen);
	return cursor != NULL;
}

/* WIRE: GOSSIPD_GOT_ONIONMSG_TO_US */
/* Tell lightningd we got a onion message (for us */
u8 *towire_gossipd_got_onionmsg_to_us(const tal_t *ctx, const struct pubkey *blinding_in, const struct pubkey *reply_blinding, const struct onionmsg_path **reply_path, const u8 *rawmsg)
{
	u16 reply_path_len = tal_count(reply_path);
	u16 rawmsg_len = tal_count(rawmsg);
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_GOSSIPD_GOT_ONIONMSG_TO_US);
	if (!blinding_in)
		towire_bool(&p, false);
	else {
		towire_bool(&p, true);
		towire_pubkey(&p, blinding_in);
	}
	if (!reply_blinding)
		towire_bool(&p, false);
	else {
		towire_bool(&p, true);
		towire_pubkey(&p, reply_blinding);
	}
	towire_u16(&p, reply_path_len);
	for (size_t i = 0; i < reply_path_len; i++)
		towire_onionmsg_path(&p, reply_path[i]);
	towire_u16(&p, rawmsg_len);
	towire_u8_array(&p, rawmsg, rawmsg_len);

	return memcheck(p, tal_count(p));
}
bool fromwire_gossipd_got_onionmsg_to_us(const tal_t *ctx, const void *p, struct pubkey **blinding_in, struct pubkey **reply_blinding, struct onionmsg_path ***reply_path, u8 **rawmsg)
{
	u16 reply_path_len;
	u16 rawmsg_len;

	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_GOSSIPD_GOT_ONIONMSG_TO_US)
		return false;
 	if (!fromwire_bool(&cursor, &plen))
		*blinding_in = NULL;
	else {
		*blinding_in = tal(ctx, struct pubkey);
		fromwire_pubkey(&cursor, &plen, *blinding_in);
	}
 	if (!fromwire_bool(&cursor, &plen))
		*reply_blinding = NULL;
	else {
		*reply_blinding = tal(ctx, struct pubkey);
		fromwire_pubkey(&cursor, &plen, *reply_blinding);
	}
 	reply_path_len = fromwire_u16(&cursor, &plen);
 	// 2nd case reply_path
	*reply_path = reply_path_len ? tal_arr(ctx, struct onionmsg_path *, reply_path_len) : NULL;
	for (size_t i = 0; i < reply_path_len; i++)
		(*reply_path)[i] = fromwire_onionmsg_path(*reply_path, &cursor, &plen);
 	rawmsg_len = fromwire_u16(&cursor, &plen);
 	// 2nd case rawmsg
	*rawmsg = rawmsg_len ? tal_arr(ctx, u8, rawmsg_len) : NULL;
	fromwire_u8_array(&cursor, &plen, *rawmsg, rawmsg_len);
	return cursor != NULL;
}

/* WIRE: GOSSIPD_GOT_ONIONMSG_FORWARD */
u8 *towire_gossipd_got_onionmsg_forward(const tal_t *ctx, const struct short_channel_id *next_scid, const struct node_id *next_node_id, const struct pubkey *next_blinding, const u8 *next_onion)
{
	u16 next_onion_len = tal_count(next_onion);
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_GOSSIPD_GOT_ONIONMSG_FORWARD);
	if (!next_scid)
		towire_bool(&p, false);
	else {
		towire_bool(&p, true);
		towire_short_channel_id(&p, next_scid);
	}
	if (!next_node_id)
		towire_bool(&p, false);
	else {
		towire_bool(&p, true);
		towire_node_id(&p, next_node_id);
	}
	if (!next_blinding)
		towire_bool(&p, false);
	else {
		towire_bool(&p, true);
		towire_pubkey(&p, next_blinding);
	}
	towire_u16(&p, next_onion_len);
	towire_u8_array(&p, next_onion, next_onion_len);

	return memcheck(p, tal_count(p));
}
bool fromwire_gossipd_got_onionmsg_forward(const tal_t *ctx, const void *p, struct short_channel_id **next_scid, struct node_id **next_node_id, struct pubkey **next_blinding, u8 **next_onion)
{
	u16 next_onion_len;

	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_GOSSIPD_GOT_ONIONMSG_FORWARD)
		return false;
 	if (!fromwire_bool(&cursor, &plen))
		*next_scid = NULL;
	else {
		*next_scid = tal(ctx, struct short_channel_id);
		fromwire_short_channel_id(&cursor, &plen, *next_scid);
	}
 	if (!fromwire_bool(&cursor, &plen))
		*next_node_id = NULL;
	else {
		*next_node_id = tal(ctx, struct node_id);
		fromwire_node_id(&cursor, &plen, *next_node_id);
	}
 	if (!fromwire_bool(&cursor, &plen))
		*next_blinding = NULL;
	else {
		*next_blinding = tal(ctx, struct pubkey);
		fromwire_pubkey(&cursor, &plen, *next_blinding);
	}
 	next_onion_len = fromwire_u16(&cursor, &plen);
 	// 2nd case next_onion
	*next_onion = next_onion_len ? tal_arr(ctx, u8, next_onion_len) : NULL;
	fromwire_u8_array(&cursor, &plen, *next_onion, next_onion_len);
	return cursor != NULL;
}

/* WIRE: GOSSIPD_SEND_ONIONMSG */
/* Lightningd tells us to send a onion message. */
u8 *towire_gossipd_send_onionmsg(const tal_t *ctx, const struct node_id *id, const u8 *onion, const struct pubkey *blinding)
{
	u16 onion_len = tal_count(onion);
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_GOSSIPD_SEND_ONIONMSG);
	towire_node_id(&p, id);
	towire_u16(&p, onion_len);
	towire_u8_array(&p, onion, onion_len);
	if (!blinding)
		towire_bool(&p, false);
	else {
		towire_bool(&p, true);
		towire_pubkey(&p, blinding);
	}

	return memcheck(p, tal_count(p));
}
bool fromwire_gossipd_send_onionmsg(const tal_t *ctx, const void *p, struct node_id *id, u8 **onion, struct pubkey **blinding)
{
	u16 onion_len;

	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_GOSSIPD_SEND_ONIONMSG)
		return false;
 	fromwire_node_id(&cursor, &plen, id);
 	onion_len = fromwire_u16(&cursor, &plen);
 	// 2nd case onion
	*onion = onion_len ? tal_arr(ctx, u8, onion_len) : NULL;
	fromwire_u8_array(&cursor, &plen, *onion, onion_len);
 	if (!fromwire_bool(&cursor, &plen))
		*blinding = NULL;
	else {
		*blinding = tal(ctx, struct pubkey);
		fromwire_pubkey(&cursor, &plen, *blinding);
	}
	return cursor != NULL;
}

/* WIRE: GOSSIPD_ADDGOSSIP */
/* Lightningd tells us to inject a gossip message (for addgossip RPC) */
u8 *towire_gossipd_addgossip(const tal_t *ctx, const u8 *msg)
{
	u16 len = tal_count(msg);
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_GOSSIPD_ADDGOSSIP);
	towire_u16(&p, len);
	towire_u8_array(&p, msg, len);

	return memcheck(p, tal_count(p));
}
bool fromwire_gossipd_addgossip(const tal_t *ctx, const void *p, u8 **msg)
{
	u16 len;

	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_GOSSIPD_ADDGOSSIP)
		return false;
 	len = fromwire_u16(&cursor, &plen);
 	// 2nd case msg
	*msg = len ? tal_arr(ctx, u8, len) : NULL;
	fromwire_u8_array(&cursor, &plen, *msg, len);
	return cursor != NULL;
}

/* WIRE: GOSSIPD_ADDGOSSIP_REPLY */
/* Empty string means no problem. */
u8 *towire_gossipd_addgossip_reply(const tal_t *ctx, const wirestring *err)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_GOSSIPD_ADDGOSSIP_REPLY);
	towire_wirestring(&p, err);

	return memcheck(p, tal_count(p));
}
bool fromwire_gossipd_addgossip_reply(const tal_t *ctx, const void *p, wirestring **err)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_GOSSIPD_ADDGOSSIP_REPLY)
		return false;
 	*err = fromwire_wirestring(ctx, &cursor, &plen);
	return cursor != NULL;
}

/* WIRE: GOSSIPD_NEW_LEASE_RATES */
/* Updated lease rates available */
u8 *towire_gossipd_new_lease_rates(const tal_t *ctx, const struct lease_rates *rates)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_GOSSIPD_NEW_LEASE_RATES);
	towire_lease_rates(&p, rates);

	return memcheck(p, tal_count(p));
}
bool fromwire_gossipd_new_lease_rates(const void *p, struct lease_rates *rates)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_GOSSIPD_NEW_LEASE_RATES)
		return false;
 	fromwire_lease_rates(&cursor, &plen, rates);
	return cursor != NULL;
}
// SHA256STAMP:ff8acca08dcaf1e1347cfd49c575c2df6ab9eb9c85a25b15ad7dbb6c181213b6
