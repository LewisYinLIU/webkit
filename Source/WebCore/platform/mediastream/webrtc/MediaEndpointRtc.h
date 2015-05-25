/*
 * Copyright (C) 2015 Ericsson AB. All rights reserved.
 * Copyright (C) 2015 Temasys Communications. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer
 *    in the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name of Ericsson nor the names of its contributors
 *    may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef MediaEndpointRtc_h
#define MediaEndpointRtc_h

#if ENABLE(MEDIA_STREAM)

#include "MediaEndpoint.h"


namespace WebCore {

class PeerMediaDescription;
class RTCConfigurationPrivate;

class MediaEndpointRtc : public MediaEndpoint {
public:
    MediaEndpointRtc(MediaEndpointClient*);
    ~MediaEndpointRtc();

    virtual void setConfiguration(RefPtr<MediaEndpointInit>&&) override;

    virtual void prepareToReceive(MediaEndpointConfiguration*, bool isInitiator) override;
    virtual void prepareToSend(MediaEndpointConfiguration*, bool isInitiator) override;

    virtual void addRemoteCandidate(IceCandidate&, unsigned mdescIndex, const String& ufrag, const String& password) override;
    
    virtual std::unique_ptr<RTCDataChannelHandler> createDataChannel(const String& label, RTCDataChannelInit_Endpoint&) override;
    
    virtual void stop() override;

    unsigned sessionIndex(RtcSession*) const;

    void dispatchNewIceCandidate(unsigned sessionIndex, RefPtr<IceCandidate>&&, const String& ufrag, const String& password);
    void dispatchGatheringDone(unsigned sessionIndex);
    void dispatchDtlsCertificate(unsigned sessionIndex, const String& certificate);
    void dispatchSendSSRC(unsigned sessionIndex, const String& ssrc, const String& cname);
    void dispatchNewDataChannel(unsigned sessionIndex, std::unique_ptr<RTCDataChannelHandler>);

private:
    enum SessionType {
        SessionTypeMedia = 1,
        SessionTypeData = 2
    };

    struct SessionConfig {
        SessionType type;
        bool isDtlsClient;
    };

    void prepareSession(RtcSession*, PeerMediaDescription*);
    void prepareMediaSession(RtcMediaSession*, PeerMediaDescription*, bool isInitiator);
    void prepareDataSession(RtcDataSession*, PeerMediaDescription*);

    void ensureTransportAgentAndSessions(bool isInitiator, const Vector<SessionConfig>& sessionConfigs);
    void internalAddRemoteCandidate(RtcSession*, IceCandidate&, const String& ufrag, const String& password);

    RefPtr<MediaEndpointInit> m_configuration;

    RtcTransportAgent* m_transportAgent;
    Vector<RtcSession*> m_sessions;
    Vector<RtcDataChannel*> m_dataChannels;

    MediaEndpointClient* m_client;

    unsigned m_numberOfReceivePreparedSessions;
    unsigned m_numberOfSendPreparedSessions;
};

} // namespace WebCore

#endif // ENABLE(MEDIA_STREAM)

#endif // MediaEndpointRtc_h
