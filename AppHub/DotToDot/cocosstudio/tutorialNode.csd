<GameFile>
  <PropertyGroup Name="tutorialNode" Type="Node" ID="e42f21a9-2e08-4187-aac7-a52c90cdc023" Version="2.3.3.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="345" Speed="1.0000" ActivedAnimationName="tutorial1">
        <Timeline ActionTag="-389050887" Property="Scale">
          <ScaleFrame FrameIndex="0" X="0.0100" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="150" X="0.0100" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="251" X="1.4000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-389050887" Property="VisibleForFrame">
          <BoolFrame FrameIndex="0" Tween="False" Value="False" />
          <BoolFrame FrameIndex="150" Tween="False" Value="True" />
        </Timeline>
        <Timeline ActionTag="1116699564" Property="Position">
          <PointFrame FrameIndex="1" X="-115.0161" Y="142.0233">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="100" X="308.0740" Y="267.3838">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="150" X="308.0700" Y="273.7500">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="275" X="506.6400" Y="475.1600">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="345" X="628.6109" Y="524.9415">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="1116699564" Property="VisibleForFrame">
          <BoolFrame FrameIndex="1" Tween="False" Value="True" />
          <BoolFrame FrameIndex="150" Tween="False" Value="False" />
          <BoolFrame FrameIndex="275" Tween="False" Value="True" />
        </Timeline>
        <Timeline ActionTag="1373183181" Property="Position">
          <PointFrame FrameIndex="100" X="308.0700" Y="267.3800">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="150" X="308.0701" Y="273.7536">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="251" X="506.6367" Y="475.1553">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="1373183181" Property="VisibleForFrame">
          <BoolFrame FrameIndex="1" Tween="False" Value="False" />
          <BoolFrame FrameIndex="150" Tween="False" Value="True" />
          <BoolFrame FrameIndex="275" Tween="False" Value="False" />
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="tutorial1" StartIndex="1" EndIndex="400">
          <RenderColor A="255" R="221" G="160" B="221" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Node" Tag="97" ctype="GameNodeObjectData">
        <Size X="0.0000" Y="0.0000" />
        <Children>
          <AbstractNodeData Name="line1" ActionTag="-389050887" VisibleForFrame="False" Tag="107" RotationSkewX="-35.0000" RotationSkewY="-48.0000" IconVisible="False" LeftMargin="300.0000" RightMargin="-500.0000" TopMargin="-307.0000" BottomMargin="293.0000" ProgressInfo="100" ctype="LoadingBarObjectData">
            <Size X="200.0000" Y="14.0000" />
            <AnchorPoint ScaleY="0.5000" />
            <Position X="300.0000" Y="300.0000" />
            <Scale ScaleX="0.0100" ScaleY="1.0000" />
            <CColor A="255" R="247" G="236" B="101" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <ImageFileData Type="Default" Path="Default/LoadingBarFile.png" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="dot4" ActionTag="1194715380" Tag="110" IconVisible="False" LeftMargin="471.5000" RightMargin="-528.5000" TopMargin="-128.5000" BottomMargin="71.5000" ctype="SpriteObjectData">
            <Size X="57.0000" Y="57.0000" />
            <Children>
              <AbstractNodeData Name="text4" CanEdit="False" ActionTag="-1430571236" Tag="111" IconVisible="False" LeftMargin="14.0000" RightMargin="21.0000" TopMargin="-39.0000" BottomMargin="4.0000" FontSize="36" LabelText="4&#xA;" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="22.0000" Y="92.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="25.0000" Y="50.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.4386" Y="0.8772" />
                <PreSize X="0.3860" Y="1.6140" />
                <FontResource Type="Normal" Path="Chalkboard.ttc" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="500.0000" Y="100.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="dot-to-dot-button unlinked.png" Plist="" />
            <BlendFunc Src="770" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="dot3" ActionTag="-1334734952" Tag="112" IconVisible="False" LeftMargin="671.5000" RightMargin="-728.5000" TopMargin="-328.5000" BottomMargin="271.5000" ctype="SpriteObjectData">
            <Size X="57.0000" Y="57.0000" />
            <Children>
              <AbstractNodeData Name="text3" ActionTag="1281904831" Tag="113" IconVisible="False" LeftMargin="15.3300" RightMargin="20.6700" TopMargin="-41.5000" BottomMargin="52.5000" FontSize="36" LabelText="3" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="21.0000" Y="46.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="25.8300" Y="75.5000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.4532" Y="1.3246" />
                <PreSize X="0.3684" Y="0.8070" />
                <FontResource Type="Normal" Path="Chalkboard.ttc" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="700.0000" Y="300.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="dot-to-dot-button unlinked.png" Plist="" />
            <BlendFunc Src="770" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="dot2" ActionTag="-1827783168" Tag="114" IconVisible="False" LeftMargin="471.5000" RightMargin="-528.5000" TopMargin="-528.5000" BottomMargin="471.5000" ctype="SpriteObjectData">
            <Size X="57.0000" Y="57.0000" />
            <Children>
              <AbstractNodeData Name="text2" ActionTag="9247452" Tag="115" IconVisible="False" LeftMargin="14.4800" RightMargin="19.5200" TopMargin="-40.1100" BottomMargin="51.1100" FontSize="36" LabelText="2" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="23.0000" Y="46.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="25.9800" Y="74.1100" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.4558" Y="1.3002" />
                <PreSize X="0.4035" Y="0.8070" />
                <FontResource Type="Normal" Path="Chalkboard.ttc" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="500.0000" Y="500.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="dot-to-dot-button unlinked.png" Plist="" />
            <BlendFunc Src="770" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="dot1" ActionTag="315064302" Tag="116" RotationSkewX="2.1792" RotationSkewY="2.1792" IconVisible="False" LeftMargin="271.5000" RightMargin="-328.5000" TopMargin="-328.5000" BottomMargin="271.5000" ctype="SpriteObjectData">
            <Size X="57.0000" Y="57.0000" />
            <Children>
              <AbstractNodeData Name="text1" ActionTag="1541305396" Tag="117" IconVisible="False" LeftMargin="17.6600" RightMargin="24.3400" TopMargin="-41.8300" BottomMargin="52.8300" FontSize="36" LabelText="1" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="15.0000" Y="46.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="25.1600" Y="75.8300" />
                <Scale ScaleX="0.9853" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.4414" Y="1.3304" />
                <PreSize X="0.2632" Y="0.8070" />
                <FontResource Type="Normal" Path="Chalkboard.ttc" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="300.0000" Y="300.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="dot-to-dot-button linked.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="cursor" ActionTag="1116699564" Tag="109" IconVisible="False" LeftMargin="279.5738" RightMargin="-336.5738" TopMargin="-329.2657" BottomMargin="206.2657" ctype="SpriteObjectData">
            <Size X="57.0000" Y="123.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="308.0738" Y="267.7657" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="Finger Black.png" Plist="" />
            <BlendFunc Src="770" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="cursorPush" ActionTag="1373183181" VisibleForFrame="False" Tag="108" IconVisible="False" LeftMargin="279.5700" RightMargin="-336.5700" TopMargin="-329.2624" BottomMargin="206.2624" ctype="SpriteObjectData">
            <Size X="57.0000" Y="123.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="308.0700" Y="267.7624" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="Finger Black ON.png" Plist="" />
            <BlendFunc Src="770" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>