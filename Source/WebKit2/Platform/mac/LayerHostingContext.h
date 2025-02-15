/*
 * Copyright (C) 2012 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef LayerHostingContext_h
#define LayerHostingContext_h

#include "LayerTreeContext.h"
#include <wtf/Forward.h>
#include <wtf/Noncopyable.h>
#include <wtf/RetainPtr.h>

OBJC_CLASS CALayer;
OBJC_CLASS CAContext;

namespace WebCore {
class MachSendRight;
}

namespace WebKit {

class LayerHostingContext {
    WTF_MAKE_NONCOPYABLE(LayerHostingContext);
public:
    static std::unique_ptr<LayerHostingContext> createForPort(const WebCore::MachSendRight& serverPort);
#if HAVE(OUT_OF_PROCESS_LAYER_HOSTING)
    static std::unique_ptr<LayerHostingContext> createForExternalHostingProcess();
#endif

    LayerHostingContext();
    ~LayerHostingContext();

    void setRootLayer(CALayer *);
    CALayer *rootLayer() const;

    uint32_t contextID() const;
    void invalidate();

    LayerHostingMode layerHostingMode() { return m_layerHostingMode; }

    void setColorSpace(CGColorSpaceRef);
    CGColorSpaceRef colorSpace() const;

    // This only works on iOS and OS 10.10+
    void setFencePort(mach_port_t);

private:
    LayerHostingMode m_layerHostingMode;
    RetainPtr<CAContext> m_context;
};

} // namespace WebKit

#endif // LayerHostingContext_h
