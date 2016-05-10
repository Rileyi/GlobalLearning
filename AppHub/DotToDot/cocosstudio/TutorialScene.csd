<GameFile>
  <PropertyGroup Name="TutorialScene" Type="Scene" ID="1b0e77f7-7826-4bef-acc7-3f3bec86039f" Version="2.3.3.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="345" Speed="1.0000" ActivedAnimationName="tutoriel1">
        <Timeline ActionTag="-1282813834" Property="Position">
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
        <Timeline ActionTag="-1282813834" Property="VisibleForFrame">
          <BoolFrame FrameIndex="1" Tween="False" Value="True" />
          <BoolFrame FrameIndex="150" Tween="False" Value="False" />
          <BoolFrame FrameIndex="275" Tween="False" Value="True" />
        </Timeline>
        <Timeline ActionTag="-113286839" Property="Position">
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
        <Timeline ActionTag="-113286839" Property="VisibleForFrame">
          <BoolFrame FrameIndex="1" Tween="False" Value="False" />
          <BoolFrame FrameIndex="150" Tween="False" Value="True" />
          <BoolFrame FrameIndex="275" Tween="False" Value="False" />
        </Timeline>
        <Timeline ActionTag="-1645111533" Property="Scale">
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
        <Timeline ActionTag="-1645111533" Property="VisibleForFrame">
          <BoolFrame FrameIndex="0" Tween="False" Value="False" />
          <BoolFrame FrameIndex="150" Tween="False" Value="True" />
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="tutoriel1" StartIndex="1" EndIndex="400">
          <RenderColor A="255" R="0" G="139" B="139" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Scene" Tag="75" ctype="GameNodeObjectData">
        <Size X="1024.0000" Y="768.0000" />
        <Children>
          <AbstractNodeData Name="Panel_1" ActionTag="794191062" Tag="76" IconVisible="False" ComboBoxIndex="2" ColorAngle="109.0000" Scale9Width="1" Scale9Height="1" ctype="PanelObjectData">
            <Size X="1024.0000" Y="768.0000" />
            <AnchorPoint />
            <Position />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="1.0000" Y="1.0000" />
            <SingleColor A="255" R="255" G="255" B="255" />
            <FirstColor A="255" R="182" G="241" B="245" />
            <EndColor A="255" R="255" G="255" B="255" />
            <ColorVector ScaleX="-0.3256" ScaleY="0.9455" />
          </AbstractNodeData>
          <AbstractNodeData Name="dot1" ActionTag="-862396981" Tag="77" RotationSkewX="2.1792" RotationSkewY="2.1792" IconVisible="False" LeftMargin="295.0000" RightMargin="719.0000" TopMargin="463.0000" BottomMargin="295.0000" ctype="SpriteObjectData">
            <Size X="10.0000" Y="10.0000" />
            <Children>
              <AbstractNodeData Name="text1" ActionTag="-549975346" Tag="82" IconVisible="False" LeftMargin="-4.8703" RightMargin="1.8703" TopMargin="-32.3635" BottomMargin="15.3635" FontSize="24" LabelText="1" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="13.0000" Y="27.0000" />
                <AnchorPoint ScaleX="0.7651" ScaleY="0.6596" />
                <Position X="5.0760" Y="33.1727" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="0" G="0" B="0" />
                <PrePosition X="0.5076" Y="3.3173" />
                <PreSize X="1.3000" Y="2.7000" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="300.0000" Y="300.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.2930" Y="0.3906" />
            <PreSize X="0.0098" Y="0.0130" />
            <FileData Type="Normal" Path="dot.png" Plist="" />
            <BlendFunc Src="770" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="dot2" ActionTag="-487138610" Tag="78" IconVisible="False" LeftMargin="495.0000" RightMargin="519.0000" TopMargin="263.0000" BottomMargin="495.0000" ctype="SpriteObjectData">
            <Size X="10.0000" Y="10.0000" />
            <Children>
              <AbstractNodeData Name="text2" ActionTag="-1473273627" Tag="83" IconVisible="False" LeftMargin="-4.0003" RightMargin="1.0003" TopMargin="-27.6923" BottomMargin="10.6923" FontSize="24" LabelText="2" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="13.0000" Y="27.0000" />
                <AnchorPoint ScaleX="0.1516" ScaleY="0.7151" />
                <Position X="-2.0295" Y="30.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="0" G="0" B="0" />
                <PrePosition X="-0.2030" Y="3.0000" />
                <PreSize X="1.3000" Y="2.7000" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="500.0000" Y="500.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.4883" Y="0.6510" />
            <PreSize X="0.0098" Y="0.0130" />
            <FileData Type="Normal" Path="dot.png" Plist="" />
            <BlendFunc Src="770" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="dot3" ActionTag="1827922659" Tag="79" IconVisible="False" LeftMargin="695.0000" RightMargin="319.0000" TopMargin="463.0000" BottomMargin="295.0000" ctype="SpriteObjectData">
            <Size X="10.0000" Y="10.0000" />
            <Children>
              <AbstractNodeData Name="text3" ActionTag="-1029042004" Tag="84" IconVisible="False" LeftMargin="-4.4997" RightMargin="1.4997" TopMargin="-33.4995" BottomMargin="16.4995" FontSize="24" LabelText="3" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="13.0000" Y="27.0000" />
                <AnchorPoint ScaleX="0.7940" ScaleY="0.5264" />
                <Position X="5.8223" Y="30.7123" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="0" G="0" B="0" />
                <PrePosition X="0.5822" Y="3.0712" />
                <PreSize X="1.3000" Y="2.7000" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="700.0000" Y="300.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.6836" Y="0.3906" />
            <PreSize X="0.0098" Y="0.0130" />
            <FileData Type="Normal" Path="dot.png" Plist="" />
            <BlendFunc Src="770" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="dot4" ActionTag="-1482015461" Tag="80" IconVisible="False" LeftMargin="495.0000" RightMargin="519.0000" TopMargin="663.0000" BottomMargin="95.0000" ctype="SpriteObjectData">
            <Size X="10.0000" Y="10.0000" />
            <Children>
              <AbstractNodeData Name="text4" CanEdit="False" ActionTag="97420432" Tag="85" IconVisible="False" LeftMargin="-4.5000" RightMargin="1.5000" TopMargin="-47.0000" BottomMargin="3.0000" FontSize="24" LabelText="4&#xA;" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="13.0000" Y="54.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="2.0000" Y="30.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="0" G="0" B="0" />
                <PrePosition X="0.2000" Y="3.0000" />
                <PreSize X="1.3000" Y="5.4000" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="500.0000" Y="100.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.4883" Y="0.1302" />
            <PreSize X="0.0098" Y="0.0130" />
            <FileData Type="Normal" Path="dot.png" Plist="" />
            <BlendFunc Src="770" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="cursor" ActionTag="-1282813834" Tag="88" IconVisible="False" LeftMargin="474.6400" RightMargin="485.3600" TopMargin="260.8400" BottomMargin="443.1600" ctype="SpriteObjectData">
            <Size X="64.0000" Y="64.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="506.6400" Y="475.1600" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.4948" Y="0.6187" />
            <PreSize X="0.0625" Y="0.0833" />
            <FileData Type="Normal" Path="cursor.png" Plist="" />
            <BlendFunc Src="770" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="cursorPush" ActionTag="-113286839" VisibleForFrame="False" Tag="89" IconVisible="False" LeftMargin="474.6367" RightMargin="485.3633" TopMargin="260.8447" BottomMargin="443.1553" ctype="SpriteObjectData">
            <Size X="64.0000" Y="64.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="506.6367" Y="475.1553" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.4948" Y="0.6187" />
            <PreSize X="0.0625" Y="0.0833" />
            <FileData Type="Normal" Path="cursorPush.png" Plist="" />
            <BlendFunc Src="770" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="line1" ActionTag="-1645111533" Tag="90" RotationSkewX="-45.0000" RotationSkewY="-44.9992" IconVisible="False" LeftMargin="300.0000" RightMargin="524.0000" TopMargin="464.5000" BottomMargin="296.5000" ProgressInfo="100" ctype="LoadingBarObjectData">
            <Size X="200.0000" Y="7.0000" />
            <AnchorPoint ScaleY="0.5000" />
            <Position X="300.0000" Y="300.0000" />
            <Scale ScaleX="1.4000" ScaleY="1.0000" />
            <CColor A="255" R="77" G="77" B="77" />
            <PrePosition X="0.2930" Y="0.3906" />
            <PreSize X="0.1953" Y="0.0091" />
            <ImageFileData Type="Default" Path="Default/LoadingBarFile.png" Plist="" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>