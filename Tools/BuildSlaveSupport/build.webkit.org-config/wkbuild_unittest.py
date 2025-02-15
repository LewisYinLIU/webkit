# Copyright (C) 2010 Apple Inc. All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1.  Redistributions of source code must retain the above copyright
#     notice, this list of conditions and the following disclaimer.
# 2.  Redistributions in binary form must reproduce the above copyright
#     notice, this list of conditions and the following disclaimer in the
#     documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS'' AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS BE LIABLE FOR
# ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
# SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
# OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

import unittest
import wkbuild


class ShouldBuildTest(unittest.TestCase):
    _should_build_tests = [
        (["ChangeLog", "Source/WebCore/ChangeLog", "Source/WebKit2/ChangeLog-2011-02-11"], []),
        (["Websites/bugs.webkit.org/foo", "Source/WebCore/bar"], ["*"]),
        (["Websites/bugs.webkit.org/foo"], []),
        (["Source/JavaScriptCore/JavaScriptCore.xcodeproj/foo"], ["mac-mavericks", "mac-yosemite"]),
        (["Source/JavaScriptCore/JavaScriptCore.vcproj/foo", "Source/WebKit2/win/WebKit2.vcproj", "Source/WebKit/win/WebKit.sln", "Tools/WebKitTestRunner/Configurations/WebKitTestRunnerCommon.vsprops"], ["win"]),
        (["LayoutTests/platform/mac/foo", "Source/WebCore/bar"], ["*"]),
        (["LayoutTests/foo"], ["*"]),
        (["LayoutTests/canvas/philip/tests/size.attributes.parse.exp-expected.txt", "LayoutTests/canvas/philip/tests/size.attributes.parse.exp.html"], ["*"]),
        (["LayoutTests/platform/mac-mavericks/foo"], ["mac-mavericks"]),
        (["LayoutTests/platform/mac-yosemite/foo"], ["mac-mavericks", "mac-yosemite"]),
        (["LayoutTests/platform/wk2/Skipped"], ["mac-mavericks", "mac-yosemite"]),
        (["LayoutTests/platform/mac-wk2/Skipped"], ["mac-mavericks", "mac-yosemite"]),
        (["LayoutTests/platform/mac-wk1/compositing/tiling/transform-origin-tiled-expected.txt"], ["mac-mavericks", "mac-yosemite"]),
        (["LayoutTests/platform/mac/foo"], ["mac-mavericks", "mac-yosemite", "win"]),
        (["LayoutTests/platform/mac-wk2/platform/mac/editing/spelling/autocorrection-contraction-expected.txt"], ["mac-mavericks", "mac-yosemite"]),
        (["LayoutTests/platform/win-xp/foo"], ["win"]),
        (["LayoutTests/platform/win-wk1/foo"], ["win"]),
        (["LayoutTests/platform/win/foo"], ["win"]),
        (["Source/WebKit/mac/WebKit.mac.exp"], ["mac-mavericks", "mac-yosemite"]),
        (["Source/WebCore/mac/foo"], ["mac-mavericks", "mac-yosemite"]),
        (["Source/WebCore/win/foo"], ["win"]),
        (["Source/WebCore/platform/wx/wxcode/win/foo"], []),
        (["Source/WebCore/accessibility/ios/AXObjectCacheIOS.mm"], []),
        (["Source/WebCore/rendering/RenderThemeMac.mm", "Source/WebCore/rendering/RenderThemeMac.h"], ["mac-mavericks", "mac-yosemite"]),
        (["Tools/BuildSlaveSupport/build.webkit.org-config/public_html/LeaksViewer/LeaksViewer.js"], []),
    ]

    def test_should_build(self):
        for files, platforms in self._should_build_tests:
            # FIXME: We should test more platforms here once
            # wkbuild._should_file_trigger_build is implemented for them.
            for platform in ["mac-mavericks", "mac-yosemite", "win"]:
                should_build = platform in platforms or "*" in platforms
                self.assertEqual(wkbuild.should_build(platform, files), should_build, "%s should%s have built but did%s (files: %s)" % (platform, "" if should_build else "n't", "n't" if should_build else "", str(files)))

# FIXME: We should run this file as part of test-rm .
# Unfortunately test-rm  currently requires that unittests
# be located in a directory with a valid module name.
# 'build.webkit.org-config' is not a valid module name (due to '.' and '-')
# so for now this is a stand-alone test harness.
if __name__ == '__main__':
    unittest.main()
