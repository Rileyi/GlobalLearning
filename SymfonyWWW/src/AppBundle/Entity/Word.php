<?php

namespace AppBundle\Entity;

use Doctrine\Common\Collections\ArrayCollection;
use Doctrine\ORM\Mapping as ORM;
use Symfony\Component\Validator\Constraints as Assert;

/**
 * @ORM\Entity(repositoryClass="AppBundle\Repository\WordRepository")
 * @ORM\Table(name="table_words")
 *
 * Defines the properties of the 'Word' entity
 * @author Paul-Axel
 */
class Word
{
    //const NUM_ITEMS = 10;

    /**
     * @var int
     *
     * @ORM\Id
     * @ORM\GeneratedValue
     * @ORM\Column(type="integer")
     */
    private $id;

    /**
     * @var string
     *
     * @ORM\Column(type="string")
     * @Assert\NotBlank
     */
    private $name;

    /**
     * @var ImagePath[]|ArrayCollection
     * @ORM\OneToMany(
     *      targetEntity="ImagePath",
     *      mappedBy="word",
     *      orphanRemoval=true
     * )
     * @ORM\OrderBy({"publishedAt": "DESC"})
     */
    private $imagePathList;

    /**
     * @var SoundPath[]|ArrayCollection
     * @ORM\OneToMany(
     *      targetEntity="SoundPath",
     *      mappedBy="word",
     *      orphanRemoval=true
     * )
     * @ORM\OrderBy({"publishedAt": "DESC"})
     */
    private $soundPathList;

    /**
     * @var string
     * @ORM\Column(type="string")
     * @Assert\NotBlank
     */
    private $authorId;

    /**
     * @var \DateTime
     *
     * @ORM\Column(type="datetime")
     * @Assert\DateTime
     */
    private $publishedAt;


    public function __construct()
    {
        $this->publishedAt = new \DateTime();
        $this->comments = new ArrayCollection();
    }

    public function getId()
    {
        return $this->id;
    }

    public function getName()
    {
        return $this->name;
    }

    /**
     * @param string $name
     */
    public function setName($name)
    {
        $this->name = $name;
    }

    public function getAuthorId()
    {
        return $this->authorId;
    }

    /**
     * @param string $authorId
     */
    public function setAuthorId($authorId)
    {
        $this->authorId = $authorId;
    }

    /**
     * Is the given User the author of this word ?
     *
     * @param User $user
     * @return bool
     */
    public function isAuthor(User $user)
    {
        return $user->getId() === $this->getAuthorId();
    }

    public function getPublishedAt()
    {
        return $this->publishedAt;
    }

    public function setPublishedAt(\DateTime $publishedAt)
    {
        $this->publishedAt = $publishedAt;
    }

    public function getSoundPathList()
    {
        return $this->soundPathList;
    }

    public function getImagePathList()
    {
        return $this->imagePathList;
    }

    /**
     * Add an ImagePath
     * @param ImagePath $imagePath
     */
    public function addImagePath(ImagePath $imagePath) {
        $this->imagePathList->add($imagePath);
        $imagePath->setWord($this);
    }

    /**
     * Remove an ImagePath
     * @param ImagePath $imagePath
     */
    public function removeImagePath(ImagePath $imagePath) {
        $this->imagePathList->removeElement($imagePath);
    }

    /**
     * Add a SoundPath
     * @param SoundPath $soundPath
     */
    public function addSoundPath(SoundPath $soundPath) {
        $this->soundPathList->add($soundPath);
        $soundPath->setWord($this);
    }

    /**
     * Remove a SoundPath
     * @param SoundPath $soundPath
     */
    public function removeSoundPath(SoundPath $soundPath) {
        $this->soundPathList->removeElement($soundPath);
    }
}
