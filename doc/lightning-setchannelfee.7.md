lightning-setchannelfee -- Command for setting specific routing fees on a lightning channel
===========================================================================================

SYNOPSIS
--------

**setchannelfee** *id* \[*base*\] \[*ppm*\]

DESCRIPTION
-----------

The **setchannelfee** RPC command sets channel specific routing fees as
defined in BOLT \#7. The channel has to be in normal or awaiting state.
This can be checked by **listpeers** reporting a *state* of
CHANNELD\_NORMAL or CHANNELD\_AWAITING\_LOCKIN for the channel.

*id* is required and should contain a scid (short channel ID), channel
id or peerid (pubkey) of the channel to be modified. If *id* is set to
"all", the fees for all channels are updated that are in state
CHANNELD\_NORMAL or CHANNELD\_AWAITING\_LOCKIN.

*base* is an optional value in millisatoshi that is added as base fee to
any routed payment. If the parameter is left out, the global config
value fee-base will be used again. It can be a whole number, or a whole
number ending in *msat* or *sat*, or a number with three decimal places
ending in *sat*, or a number with 1 to 11 decimal places ending in
*btc*.

*ppm* is an optional value that is added proportionally per-millionths
to any routed payment volume in satoshi. For example, if ppm is 1,000
and 1,000,000 satoshi is being routed through the channel, an
proportional fee of 1,000 satoshi is added, resulting in a 0.1% fee. If
the parameter is left out, the global config value will be used again.

RETURN VALUE
------------

[comment]: # (GENERATE-FROM-SCHEMA-START)
On success, an object is returned, containing:
- **base** (u32): The fee_base_msat value
- **ppm** (u32): The fee_proportional_millionths value
- **channels** (array of objects): channel(s) whose rate is now set:
  - **peer_id** (pubkey): The node_id of the peer
  - **channel_id** (hex): The channel_id of the channel (always 64 characters)
  - **short_channel_id** (short_channel_id, optional): the short_channel_id (if locked in)

[comment]: # (GENERATE-FROM-SCHEMA-END)

ERRORS
------

The following error codes may occur:
- -1: Channel is in incorrect state, i.e. Catchall nonspecific error.
- -32602: JSONRPC2\_INVALID\_PARAMS, i.e. Given id is not a channel ID
or short channel ID.

AUTHOR
------

Michael Schmoock <<michael@schmoock.net>> is the author of this
feature. Rusty Russell <<rusty@rustcorp.com.au>> is mainly
responsible for the c-lightning project.

SEE ALSO
--------

lightningd-config(5), lightning-fundchannel(7),
lightning-listchannels(7), lightning-listpeers(7)

RESOURCES
---------

Main web site: <https://github.com/ElementsProject/lightning>

[comment]: # ( SHA256STAMP:1f040269076ac47e5ed973225bfddbcffdec83dd91f6df143d29bcb981de04ed)
