/*
 * Copyright (C) 2015 Ericsson AB. All rights reserved.
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

#ifndef IceCandidate_h
#define IceCandidate_h

#if ENABLE(MEDIA_STREAM)

#include <wtf/RefCounted.h>
#include <wtf/RefPtr.h>
#include <wtf/text/WTFString.h>

namespace WebCore {

class IceCandidate : public RefCounted<IceCandidate> {
public:
    static RefPtr<IceCandidate> create()
    {
        return adoptRef(new IceCandidate());
    }
    virtual ~IceCandidate() { }

    const String& type() const { return m_type; }
    void setType(const String& type) { m_type = type; }

    const String& foundation() const { return m_foundation; }
    void setFoundation(const String& foundation) { m_foundation = foundation; }

    unsigned componentId() const { return m_componentId; }
    void setComponentId(unsigned componentId) { m_componentId = componentId; }

    const String& transport() const { return m_transport; }
    void setTransport(const String& transport) { m_transport = transport; }

    int priority() const { return m_priority; }
    void setPriority(int priority) { m_priority = priority; }

    const String& address() const { return m_address; }
    void setAddress(const String& address) { m_address = address; }

    unsigned port() const { return m_port; }
    void setPort(unsigned port) { m_port = port; }

    const String& tcpType() const { return m_tcpType; }
    void setTcpType(const String& tcpType) { m_tcpType = tcpType; }

    const String& relatedAddress() const { return m_relatedAddress; }
    void setRelatedAddress(const String& relatedAddress) { m_relatedAddress = relatedAddress; }

    unsigned relatedPort() const { return m_relatedPort; }
    void setRelatedPort(unsigned relatedPort) { m_relatedPort = relatedPort; }

private:
    IceCandidate()
        : m_componentId(0)
        , m_priority(0)
        , m_port(0)
        , m_relatedPort(0)
    { }

    String m_type;
    String m_foundation;
    unsigned m_componentId;
    String m_transport;
    int m_priority;
    String m_address;
    unsigned m_port;
    String m_tcpType;
    String m_relatedAddress;
    unsigned m_relatedPort;
};

} // namespace WebCore

#endif // ENABLE(MEDIA_STREAM)

#endif // IceCandidate_h
