/****
 * Sming Framework Project - Open Source framework for high efficiency native ESP8266 development.
 * Created 2015 by Skurydin Alexey
 * http://github.com/anakod/Sming
 *
 * @author: 2017 - Slavey Karadzhov <slav@attachix.com>
 *
 * All files of the Sming Core are provided under the LGPL v3 license.
 ****/

#ifndef _SMING_SMINGCORE_NETWORK_WEBSOCKET_RESOURCE_H_
#define _SMING_SMINGCORE_NETWORK_WEBSOCKET_RESOURCE_H_

#include "../HttpServerConnection.h"
#include "../HttpResource.h"
#include "WebsocketConnection.h"
#include "WString.h"

class WebsocketResource : public HttpResource
{
public:
	WebsocketResource()
	{
		onHeadersComplete = HttpResourceDelegate(&WebsocketResource::checkHeaders, this);
	}

	virtual int checkHeaders(HttpServerConnection& connection, HttpRequest& request, HttpResponse& response);

	void shutdown(HttpServerConnection& connection) override;

	void setConnectionHandler(WebsocketDelegate handler)
	{
		wsConnect = handler;
	}

	void setMessageHandler(WebsocketMessageDelegate handler)
	{
		wsMessage = handler;
	}

	void setBinaryHandler(WebsocketBinaryDelegate handler)
	{
		wsBinary = handler;
	}

	void setDisconnectionHandler(WebsocketDelegate handler)
	{
		wsDisconnect = handler;
	}

protected:
	bool onConnect();

protected:
	WebsocketDelegate wsConnect = nullptr;
	WebsocketMessageDelegate wsMessage = nullptr;
	WebsocketBinaryDelegate wsBinary = nullptr;
	WebsocketDelegate wsDisconnect = nullptr;
};

#endif /* _SMING_SMINGCORE_NETWORK_WEBSOCKET_RESOURCE_H_ */
