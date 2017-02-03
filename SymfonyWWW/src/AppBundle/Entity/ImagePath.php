<?php

namespace AppBundle\Entity;

use Doctrine\ORM\Mapping as ORM;
use Symfony\Component\Validator\Constraints as Assert;

/**
 * @ORM\Entity
 * @ORM\Table(name="table_image_path")
 *
 * @author Paul-Axel MARIE
 */
class ImagePath
{
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
     * @ORM\ManyToOne(targetEntity="Word", inversedBy="imagePath")
     * @ORM\JoinColumn(nullable=false)
     */
    private $word;

    /**
     * @var string
     *
     * @ORM\Column(type="string")
     * @Assert\NotBlank
     */
    private $path;

    /**
     * @var string
     *
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
    }

    /// ----
    /// Getters
    /// ----------
    public function getId() { return $this->id; }
    public function getWord() { return $this->word; }
    public function getPath() { return $this->path; }
    public function getAuthorId() { return $this->authorId; }
    public function getPublishedAt() { return $this->publishedAt; }

    /// ----
    /// Setters
    /// ----------

    /**
     * @param string $id
     */
    public function setId($id) { $this->id = $id; }

    /**
     * @param string $word
     */
    public function setWord($word) { $this->word = $word; }

    /**
     * @param string $path
     */
    public function setPath($path) { $this->path = $path; }

    /**
     * @param int $authorId
     */
    public function setAuthorId($authorId) { $this->authorId = $authorId; }

    /**
     * @param \DateTime $publishedAt
     */
    public function setPublishedAt(\DateTime $publishedAt) { $this->publishedAt = $publishedAt; }

}
