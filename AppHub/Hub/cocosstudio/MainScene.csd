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
          <RenderColor A="255" R="245" G="245" B="245" />
        </AnimationInfo>
        <AnimationInfo Name="button_left" StartIndex="40" EndIndex="80">
          <RenderColor A="255" R="0" G="255" B="255" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Scene" ctype="GameNodeObjectData">
        <Size X="1024.0000" Y="768.0000" />
        <Children>
          <AbstractNodeData Name="background_mainscene" ActionTag="369333060" Tag="16" IconVisible="False" TopMargin="69.0000" ctype="SpriteObjectData">
            <Size X="1024.0000" Y="699.0000" />
            <AnchorPoint />
            <Position />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="1.0000" Y="0.9102" />
            <FileData Type="Normal" Path="background_mainscene.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="Tool_bar" ActionTag="-224764501" Tag="17" IconVisible="True" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentWidthEnabled="True" LeftMargin="512.0000" RightMargin="512.0000" BottomMargin="768.0000" StretchWidthEnable="False" StretchHeightEnable="False" InnerActionSpeed="1.0000" CustomSizeEnabled="False" ctype="ProjectNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <AnchorPoint />
            <Position X="512.0000" Y="768.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="1.0000" />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="ToolBar.csd" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="Play_button" ActionTag="-552034169" Tag="31" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="401.0000" RightMargin="401.0000" TopMargin="172.2270" BottomMargin="538.7730" TouchEnable="True" FontSize="30" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="192" Scale9Height="35" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="222.0000" Y="57.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="1.0000" />
            <Position X="512.0000" Y="595.7730" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.7757" />
            <PreSize X="0.2168" Y="0.0742" />
            <TextColor A="255" R="0" G="0" B="0" />
            <DisabledFileData Type="Normal" Path="boutons/button Learn ON.png" Plist="" />
            <PressedFileData Type="Normal" Path="boutons/button Learn ON.png" Plist="" />
            <NormalFileData Type="Normal" Path="boutons/button Learn.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="Shahoots_button" ActionTag="-2065525927" Tag="32" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="401.0000" RightMargin="401.0000" TopMargin="342.8033" BottomMargin="368.1967" TouchEnable="True" FontSize="30" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="192" Scale9Height="35" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="222.0000" Y="57.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="1.0000" />
            <Position X="512.0000" Y="425.1967" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5536" />
            <PreSize X="0.2168" Y="0.0742" />
            <TextColor A="255" R="0" G="0" B="0" />
            <DisabledFileData Type="Normal" Path="boutons/button Shahoots ON.png" Plist="" />
            <PressedFileData Type="Normal" Path="boutons/button Shahoots ON.png" Plist="" />
            <NormalFileData Type="Normal" Path="boutons/button Shahoots.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="Exit_button" ActionTag="761676449" Tag="33" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="401.0000" RightMargin="401.0000" TopMargin="505.9632" BottomMargin="205.0368" TouchEnable="True" FontSize="30" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="192" Scale9Height="35" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="222.0000" Y="57.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="1.0000" />
            <Position X="512.0000" Y="262.0368" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.3412" />
            <PreSize X="0.2168" Y="0.0742" />
            <TextColor A="255" R="0" G="0" B="0" />
            <DisabledFileData Type="Normal" Path="boutons/button Exit ON.png" Plist="" />
            <PressedFileData Type="Normal" Path="boutons/button Exit ON.png" Plist="" />
            <NormalFileData Type="Normal" Path="boutons/button Exit.png" Plist="" />
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