<GameFile>
  <PropertyGroup Name="MainScene" Type="Scene" ID="a2ee0952-26b5-49ae-8bf9-4f1d6279b798" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="80" Speed="1.0000" ActivedAnimationName="button_left">
        <Timeline ActionTag="-552034169" Property="Position">
          <PointFrame FrameIndex="0" X="512.0000" Y="1152.0000">
            <EasingData Type="8" />
          </PointFrame>
          <PointFrame FrameIndex="40" X="512.0000" Y="576.0000">
            <EasingData Type="10" />
          </PointFrame>
          <PointFrame FrameIndex="80" X="1536.0000" Y="576.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="-2065525927" Property="Position">
          <PointFrame FrameIndex="0" X="512.0000" Y="1152.0000">
            <EasingData Type="8" />
          </PointFrame>
          <PointFrame FrameIndex="40" X="512.0000" Y="399.3600">
            <EasingData Type="10" />
          </PointFrame>
          <PointFrame FrameIndex="80" X="1536.0000" Y="399.3600">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="761676449" Property="Position">
          <PointFrame FrameIndex="0" X="512.0000" Y="1152.0000">
            <EasingData Type="8" />
          </PointFrame>
          <PointFrame FrameIndex="40" X="512.0000" Y="230.4000">
            <EasingData Type="10" />
          </PointFrame>
          <PointFrame FrameIndex="80" X="1536.0000" Y="230.4000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="button_appeared" StartIndex="0" EndIndex="40">
          <RenderColor A="150" R="245" G="245" B="245" />
        </AnimationInfo>
        <AnimationInfo Name="button_left" StartIndex="40" EndIndex="80">
          <RenderColor A="150" R="0" G="255" B="255" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Scene" ctype="GameNodeObjectData">
        <Size X="1024.0000" Y="768.0000" />
        <Children>
          <AbstractNodeData Name="background_mainscene" ActionTag="369333060" Tag="16" IconVisible="False" LeftMargin="-1.3010" RightMargin="1.3010" ctype="SpriteObjectData">
            <Size X="1024.0000" Y="768.0000" />
            <AnchorPoint />
            <Position X="-1.3010" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="-0.0013" />
            <PreSize X="1.0000" Y="1.0000" />
            <FileData Type="Normal" Path="background_mainscene.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="Tool_bar" ActionTag="-224764501" VisibleForFrame="False" Tag="17" IconVisible="True" PercentWidthEnable="True" PercentWidthEnabled="True" BottomMargin="708.0000" StretchWidthEnable="False" StretchHeightEnable="False" InnerActionSpeed="1.0000" CustomSizeEnabled="False" ctype="ProjectNodeObjectData">
            <Size X="1024.0000" Y="60.0000" />
            <AnchorPoint />
            <Position Y="708.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition Y="0.9219" />
            <PreSize X="1.0000" Y="0.0781" />
            <FileData Type="Normal" Path="ToolBar.csd" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="Play_button" ActionTag="-552034169" Tag="31" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="399.5000" RightMargin="399.5000" TopMargin="192.0000" BottomMargin="486.0000" TouchEnable="True" FontSize="30" ButtonText="Play" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="16" Scale9Height="14" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="225.0000" Y="90.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="1.0000" />
            <Position X="512.0000" Y="576.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.7500" />
            <PreSize X="0.2197" Y="0.1172" />
            <TextColor A="255" R="0" G="0" B="0" />
            <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
            <PressedFileData Type="Default" Path="Default/Button_Press.png" Plist="" />
            <NormalFileData Type="Default" Path="Default/Button_Normal.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="Shahoots_button" ActionTag="-2065525927" Tag="32" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="399.5000" RightMargin="399.5000" TopMargin="368.6400" BottomMargin="309.3600" TouchEnable="True" FontSize="30" ButtonText="Shahoots" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="16" Scale9Height="14" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="225.0000" Y="90.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="1.0000" />
            <Position X="512.0000" Y="399.3600" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5200" />
            <PreSize X="0.2197" Y="0.1172" />
            <TextColor A="255" R="0" G="0" B="0" />
            <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
            <PressedFileData Type="Default" Path="Default/Button_Press.png" Plist="" />
            <NormalFileData Type="Default" Path="Default/Button_Normal.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="Exit_button" ActionTag="761676449" Tag="33" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="399.5000" RightMargin="399.5000" TopMargin="537.6000" BottomMargin="140.4000" TouchEnable="True" FontSize="30" ButtonText="Exit" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="16" Scale9Height="14" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="225.0000" Y="90.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="1.0000" />
            <Position X="512.0000" Y="230.4000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.3000" />
            <PreSize X="0.2197" Y="0.1172" />
            <TextColor A="255" R="0" G="0" B="0" />
            <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
            <PressedFileData Type="Default" Path="Default/Button_Press.png" Plist="" />
            <NormalFileData Type="Default" Path="Default/Button_Normal.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="Mascotte" ActionTag="-600729337" VisibleForFrame="False" Tag="34" IconVisible="True" LeftMargin="815.7191" RightMargin="208.2809" TopMargin="607.9780" BottomMargin="160.0220" StretchWidthEnable="False" StretchHeightEnable="False" InnerActionSpeed="1.0000" CustomSizeEnabled="False" ctype="ProjectNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <AnchorPoint />
            <Position X="815.7191" Y="160.0220" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.7966" Y="0.2084" />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="Mascotte.csd" Plist="" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>